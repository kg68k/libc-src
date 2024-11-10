#
# PROJECT C Library, X68000 PROGRAMMING INTERFACE DEFINITION
# --------------------------------------------------------------------
# This file is written by the Project C Library Group,  and completely
# in public domain. You can freely use, copy, modify, and redistribute
# the whole contents, without this notice.
# --------------------------------------------------------------------
# $Id: _split.awk,v 1.3 1994/07/31 17:22:40 mura Exp $
#

BEGIN {
    FILE = 0;
}

/\.cpu 68000/ {
    sub($0, ".cpu 68030");
}

/globl/ && /__fpu/ {
    FILE = 1;
}

FILE == 0 {
    print $0 > tmp1;
}

FILE == 1 {
    print $0 > tmp2;
}

FILE == 2 {
    print $0 > tmp3;
}

FILE == 1 && /rts/ {
    FILE = 2;
}

