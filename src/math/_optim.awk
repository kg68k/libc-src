#
# PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
# --------------------------------------------------------------------
# This file is written by the Project C Library Group,  and completely
# in public domain. You can freely use, copy, modify, and redistribute
# the whole contents, without this notice.
# --------------------------------------------------------------------
# $Id: _optim.awk,v 1.2 1993/06/24 17:29:42 mura Exp $
#

BEGIN {
    FS="[\t ,]";	# ラベル、ニーモニック、オペランド１、オペランド２
    IO_NUM = 0;
    LINE = 0;
    LINE_ON = 0;
    REG_MAX = 3;	# 使用出来るアドレスレジスタ数 A0 - A(n-1)
}

/__fpu/ {
    LINE_ON = 1;
}

# コメント以外の行をバッファに格納
LINE_ON && (! /^*/) {
    sub ("\t\t", "\t", $0);
    sub ("\*-6", "\*-2", $0);
    sub ("\*-8", "\*-4", $0);
    buf[LINE++] = $0;
}

# アドレスレジスタ使用リストを作る（オペランド１）
LINE_ON && ($3 ~ /^a[0-7]/ || $3 ~ /(a[0-7])/) {
    n = substr ($3, index ($3, "a") + 1, 1);
    areg[n]++;
}

# アドレスレジスタ使用リストを作る（オペランド２）
LINE_ON && ($4 ~ /^a[0-7]/ || $4 ~ /(a[0-7])/) {
    n = substr ($4, index ($4, "a") + 1, 1);
    areg[n]++;
}

# コプロＩ／Ｏ使用リストを作る
function make_io_list (addr) {
    if (io_use[addr] == 0)
	io_lst[IO_NUM++] = addr;
    io_use[addr]++;
}

# コプロＩ／Ｏ使用リストを作る（オペランド１）
LINE_ON && ($3 ~ /[Ee]9[Ee]0[0-1][0-9A-Fa-f]/) {
    make_io_list($3);
}

# コプロＩ／Ｏ使用リストを作る（オペランド２）
LINE_ON && ($4 ~ /[Ee]9[Ee]0[0-1][0-9A-Fa-f]/) {
    make_io_list($4);
}

LINE_ON && ($2 ~/rts/) {
    LINE_ON = 0;
}

END {
    bsort(IO_NUM, io_use, io_lst);
    report();
# リストのＩ／Ｏアドレスを置換する
    flag = 0;
    for (l = 0; l < LINE; l++) {
	if (flag != 0) {
	    if (buf[l] ~ /[Ee]9[Ee]0[0-1][0-9A-Fa-f]/) {
# アドレスレジスタ間接にする
		for (i = 0; i < limit; i++)
		    gsub (io_lst[i], "(a" use_reg[i] ")", buf[l]);
# 最初のアドレスレジスタでディスプレースメント間接にする
		for (i = limit; i < IO_NUM; i++) {
		    offset = hextodec(io_lst[i]) - hextodec(base_adr);
		    gsub (io_lst[i], offset "(a" base_reg ")", buf[l]);
	        }
	    }
	    gsub ("a7", "sp", buf[l]);
	    printf (buf[l] "\n");
	}
	else if (buf[l] ~ /:$/) {
	    printf (buf[l] "\n");
	    limit = addcode(IO_NUM);
            flag = 1;
	}
	else if (buf[l] ~ /__fpu/)
	    printf (buf[l] "\n");
    }
}

# 使用アドレスレジスタを報告する
function report (i, j, base, reg) {
    base = 0;
    reg = -1;
    for(i = 0; i < IO_NUM; i++) {
	printf ("*\tI/O %s %d回 --> ", io_lst[i], io_use[io_lst[i]]);
	for (j = base; j < REG_MAX; j++) {
	    if (areg[j] == 0) {
		printf ("A%s\n", j);
		base = j + 1;
		if (reg == -1)
		    reg = j;
		break;
	    }
	}
	if (j == REG_MAX) {
	    if (base == 0) {
		printf ("レジスタの空きがぜんぜんないよぉ\n") > "/dev/stderr";
		exit(1);
	    }
	    offset = hextodec(io_lst[i]) - hextodec(io_lst[0]);
	    printf ("%d(A%d)\n", offset, reg);
	}
    }
}

# 使用頻度の高いＩ／Ｏ順に io_lst[] を並べ替える
function bsort (n, io_use, io_lst, i, j, k, t) {
    k = n - 1;
    while (k >= 0) {
	j = -1;
	for (i = 1; i <= k; i++)
	    if (io_use[io_lst[i-1]] < io_use[io_lst[i]]) {
		j = i - 1;
		t = io_lst[j];
		io_lst[j] = io_lst[i];
		io_lst[i] = t;
	    }
	k = j;
    }
}

# 使用Ｉ／Ｏアドレスを空きレジスタに代入
function addcode (io_num, i, j, flag, offset) {
    for (i = 0; i < io_num; i++) {
	flag = 0;
# レジスタの空きを調べる
	for (j = 0; j < REG_MAX; j++) {
	    if (areg[j] == 0) {
		areg[j] = 1;
		flag = 1;
		break;
	    }
	}
# レジスタの空きが足りない場合
        if (flag == 0) {
	    io_num = i;
	    break;
	}
	if(i == 0) {
	    printf ("\tlea.l\t%s,a%d\n", io_lst[i], j);
	    base_reg = j;
	    base_adr = io_lst[i];
	}
	else {
	    offset = hextodec(io_lst[i]) - hextodec(base_adr);
	    printf ("\tlea.l\t%d(a%d),a%d\n", offset, base_reg, j);
	}
	use_reg[i] = j;
    }
    return io_num;
}

# ほんとにこんなのつくらなあかんのかいな？
function hextodec (str, num, dec, i, j) {
    dec = 0;
    j = 0;
    for (i = length (str); i > 1; i--) {
	num = substr (str, i, 1)
	if(num == "A" || num == "a" )
	    num = 10;
	else if(num == "B" || num == "b" )
	    num = 11;
	else if(num == "C" || num == "c" )
	    num = 12;
	else if(num == "D" || num == "d" )
	    num = 13;
	else if(num == "E" || num == "e" )
	    num = 14;
	else if(num == "F" || num == "f" )
	    num = 15;
        dec += num * (16 ^ j++);
    }
    return dec;
}
