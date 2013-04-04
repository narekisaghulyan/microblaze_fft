/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x8ddf5b5d */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/cc/cs150/sp13/class/cs150-ad/pcores/gcd_coprocessor_v1_00_a/hdl/verilog/gcd_coprocessor.v";
static unsigned int ng1[] = {2U, 0U};
static int ng2[] = {0, 0};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {4U, 0U};
static int ng5[] = {1, 0};
static unsigned int ng6[] = {3U, 0U};



static void Cont_168_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t8[8];
    char t37[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;

LAB0:    t1 = (t0 + 5736U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(168, ng0);
    t2 = (t0 + 4344);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB7;

LAB4:    if (t20 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t8) = 1;

LAB7:    memset(t4, 0, 8);
    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t24) != 0)
        goto LAB10;

LAB11:    t31 = (t4 + 4);
    t32 = *((unsigned int *)t4);
    t33 = *((unsigned int *)t31);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB12;

LAB13:    t38 = *((unsigned int *)t4);
    t39 = (~(t38));
    t40 = *((unsigned int *)t31);
    t41 = (t39 || t40);
    if (t41 > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t31) > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t4) > 0)
        goto LAB18;

LAB19:    memcpy(t3, t35, 8);

LAB20:    t42 = (t0 + 6928);
    t43 = (t42 + 56U);
    t44 = *((char **)t43);
    t45 = (t44 + 56U);
    t46 = *((char **)t45);
    memset(t46, 0, 8);
    t47 = 1U;
    t48 = t47;
    t49 = (t3 + 4);
    t50 = *((unsigned int *)t3);
    t47 = (t47 & t50);
    t51 = *((unsigned int *)t49);
    t48 = (t48 & t51);
    t52 = (t46 + 4);
    t53 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t53 | t47);
    t54 = *((unsigned int *)t52);
    *((unsigned int *)t52) = (t54 | t48);
    xsi_driver_vfirst_trans(t42, 0, 0);
    t55 = (t0 + 6800);
    *((int *)t55) = 1;

LAB1:    return;
LAB6:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB11;

LAB10:    t30 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB11;

LAB12:    t35 = (t0 + 2824U);
    t36 = *((char **)t35);
    memcpy(t37, t36, 8);
    goto LAB13;

LAB14:    t35 = ((char*)((ng2)));
    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 32, t37, 32, t35, 32);
    goto LAB20;

LAB18:    memcpy(t3, t37, 8);
    goto LAB20;

}

static void Cont_169_1(char *t0)
{
    char t3[8];
    char t4[8];
    char t8[8];
    char t35[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;

LAB0:    t1 = (t0 + 5984U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(169, ng0);
    t2 = (t0 + 4344);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB7;

LAB4:    if (t20 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t8) = 1;

LAB7:    memset(t4, 0, 8);
    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t24) != 0)
        goto LAB10;

LAB11:    t31 = (t4 + 4);
    t32 = *((unsigned int *)t4);
    t33 = *((unsigned int *)t31);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB12;

LAB13:    t54 = *((unsigned int *)t4);
    t55 = (~(t54));
    t56 = *((unsigned int *)t31);
    t57 = (t55 || t56);
    if (t57 > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t31) > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t4) > 0)
        goto LAB18;

LAB19:    memcpy(t3, t58, 8);

LAB20:    t59 = (t0 + 6992);
    t60 = (t59 + 56U);
    t61 = *((char **)t60);
    t62 = (t61 + 56U);
    t63 = *((char **)t62);
    memset(t63, 0, 8);
    t64 = 1U;
    t65 = t64;
    t66 = (t3 + 4);
    t67 = *((unsigned int *)t3);
    t64 = (t64 & t67);
    t68 = *((unsigned int *)t66);
    t65 = (t65 & t68);
    t69 = (t63 + 4);
    t70 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t70 | t64);
    t71 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t71 | t65);
    xsi_driver_vfirst_trans(t59, 0, 0);
    t72 = (t0 + 6816);
    *((int *)t72) = 1;

LAB1:    return;
LAB6:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB11;

LAB10:    t30 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB11;

LAB12:    t36 = (t0 + 3624U);
    t37 = *((char **)t36);
    memset(t35, 0, 8);
    t36 = (t37 + 4);
    t38 = *((unsigned int *)t36);
    t39 = (~(t38));
    t40 = *((unsigned int *)t37);
    t41 = (t40 & t39);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB24;

LAB22:    if (*((unsigned int *)t36) == 0)
        goto LAB21;

LAB23:    t43 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t43) = 1;

LAB24:    t44 = (t35 + 4);
    t45 = (t37 + 4);
    t46 = *((unsigned int *)t37);
    t47 = (~(t46));
    *((unsigned int *)t35) = t47;
    *((unsigned int *)t44) = 0;
    if (*((unsigned int *)t45) != 0)
        goto LAB26;

LAB25:    t52 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t52 & 4294967295U);
    t53 = *((unsigned int *)t44);
    *((unsigned int *)t44) = (t53 & 4294967295U);
    goto LAB13;

LAB14:    t58 = ((char*)((ng2)));
    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 32, t35, 32, t58, 32);
    goto LAB20;

LAB18:    memcpy(t3, t35, 8);
    goto LAB20;

LAB21:    *((unsigned int *)t35) = 1;
    goto LAB24;

LAB26:    t48 = *((unsigned int *)t35);
    t49 = *((unsigned int *)t45);
    *((unsigned int *)t35) = (t48 | t49);
    t50 = *((unsigned int *)t44);
    t51 = *((unsigned int *)t45);
    *((unsigned int *)t44) = (t50 | t51);
    goto LAB25;

}

static void Cont_171_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 6232U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(171, ng0);
    t2 = (t0 + 4504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7056);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t4, 8);
    xsi_driver_vfirst_trans(t5, 0, 31);
    t10 = (t0 + 6832);
    *((int *)t10) = 1;

LAB1:    return;
}

static void Always_173_3(char *t0)
{
    char t14[8];
    char t33[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    char *t56;

LAB0:    t1 = (t0 + 6480U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(173, ng0);
    t2 = (t0 + 6848);
    *((int *)t2) = 1;
    t3 = (t0 + 6512);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(174, ng0);

LAB5:    xsi_set_current_line(175, ng0);
    t4 = (t0 + 2024U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(185, ng0);
    t2 = (t0 + 4344);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB10:    t5 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t13 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng1)));
    t13 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t13 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng6)));
    t13 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t13 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng3)));
    t13 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t13 == 1)
        goto LAB17;

LAB18:
LAB19:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(176, ng0);

LAB9:    xsi_set_current_line(179, ng0);
    t11 = ((char*)((ng4)));
    t12 = (t0 + 4344);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 3, 0LL);
    xsi_set_current_line(180, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4664);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 0LL);
    xsi_set_current_line(181, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4824);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(182, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4504);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    goto LAB8;

LAB11:    xsi_set_current_line(187, ng0);
    t11 = (t0 + 2824U);
    t12 = *((char **)t11);
    t11 = ((char*)((ng5)));
    memset(t14, 0, 8);
    t15 = (t12 + 4);
    t16 = (t11 + 4);
    t6 = *((unsigned int *)t12);
    t7 = *((unsigned int *)t11);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t15);
    t10 = *((unsigned int *)t16);
    t17 = (t9 ^ t10);
    t18 = (t8 | t17);
    t19 = *((unsigned int *)t15);
    t20 = *((unsigned int *)t16);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB23;

LAB20:    if (t21 != 0)
        goto LAB22;

LAB21:    *((unsigned int *)t14) = 1;

LAB23:    t25 = (t14 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (~(t26));
    t28 = *((unsigned int *)t14);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB19;

LAB13:    xsi_set_current_line(195, ng0);
    t3 = (t0 + 2824U);
    t5 = *((char **)t3);
    t3 = ((char*)((ng5)));
    memset(t14, 0, 8);
    t11 = (t5 + 4);
    t12 = (t3 + 4);
    t6 = *((unsigned int *)t5);
    t7 = *((unsigned int *)t3);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t17 = (t9 ^ t10);
    t18 = (t8 | t17);
    t19 = *((unsigned int *)t11);
    t20 = *((unsigned int *)t12);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB31;

LAB28:    if (t21 != 0)
        goto LAB30;

LAB29:    *((unsigned int *)t14) = 1;

LAB31:    t16 = (t14 + 4);
    t26 = *((unsigned int *)t16);
    t27 = (~(t26));
    t28 = *((unsigned int *)t14);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB32;

LAB33:
LAB34:    goto LAB19;

LAB15:    xsi_set_current_line(211, ng0);

LAB51:    xsi_set_current_line(212, ng0);
    t3 = (t0 + 4024);
    t5 = (t3 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 4184);
    t15 = (t12 + 56U);
    t16 = *((char **)t15);
    memset(t14, 0, 8);
    t24 = (t11 + 4);
    if (*((unsigned int *)t24) != 0)
        goto LAB53;

LAB52:    t25 = (t16 + 4);
    if (*((unsigned int *)t25) != 0)
        goto LAB53;

LAB56:    if (*((unsigned int *)t11) < *((unsigned int *)t16))
        goto LAB54;

LAB55:    t32 = (t14 + 4);
    t6 = *((unsigned int *)t32);
    t7 = (~(t6));
    t8 = *((unsigned int *)t14);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB57;

LAB58:    xsi_set_current_line(217, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = ((char*)((ng2)));
    memset(t14, 0, 8);
    if (*((unsigned int *)t5) != *((unsigned int *)t11))
        goto LAB62;

LAB61:    t12 = (t5 + 4);
    t15 = (t11 + 4);
    if (*((unsigned int *)t12) != *((unsigned int *)t15))
        goto LAB62;

LAB63:    t16 = (t14 + 4);
    t6 = *((unsigned int *)t16);
    t7 = (~(t6));
    t8 = *((unsigned int *)t14);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB64;

LAB65:    xsi_set_current_line(221, ng0);

LAB68:    xsi_set_current_line(222, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 4344);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(223, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = (t0 + 4504);
    xsi_vlogvar_wait_assign_value(t11, t5, 0, 0, 32, 0LL);

LAB66:
LAB59:    goto LAB19;

LAB17:    xsi_set_current_line(230, ng0);
    t3 = (t0 + 4824);
    t5 = (t3 + 56U);
    t11 = *((char **)t5);
    t12 = ((char*)((ng2)));
    memset(t14, 0, 8);
    t15 = (t11 + 4);
    t16 = (t12 + 4);
    t6 = *((unsigned int *)t11);
    t7 = *((unsigned int *)t12);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t15);
    t10 = *((unsigned int *)t16);
    t17 = (t9 ^ t10);
    t18 = (t8 | t17);
    t19 = *((unsigned int *)t15);
    t20 = *((unsigned int *)t16);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB72;

LAB69:    if (t21 != 0)
        goto LAB71;

LAB70:    *((unsigned int *)t14) = 1;

LAB72:    t25 = (t14 + 4);
    t26 = *((unsigned int *)t25);
    t27 = (~(t26));
    t28 = *((unsigned int *)t14);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB73;

LAB74:    xsi_set_current_line(233, ng0);
    t2 = (t0 + 3624U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t14, 0, 8);
    t5 = (t3 + 4);
    t11 = (t2 + 4);
    t6 = *((unsigned int *)t3);
    t7 = *((unsigned int *)t2);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t11);
    t17 = (t9 ^ t10);
    t18 = (t8 | t17);
    t19 = *((unsigned int *)t5);
    t20 = *((unsigned int *)t11);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB79;

LAB76:    if (t21 != 0)
        goto LAB78;

LAB77:    *((unsigned int *)t14) = 1;

LAB79:    t15 = (t14 + 4);
    t26 = *((unsigned int *)t15);
    t27 = (~(t26));
    t28 = *((unsigned int *)t14);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB80;

LAB81:
LAB82:
LAB75:    goto LAB19;

LAB22:    t24 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB23;

LAB24:    xsi_set_current_line(188, ng0);

LAB27:    xsi_set_current_line(189, ng0);
    t31 = ((char*)((ng1)));
    t32 = (t0 + 4344);
    xsi_vlogvar_wait_assign_value(t32, t31, 0, 0, 3, 0LL);
    xsi_set_current_line(190, ng0);
    t2 = (t0 + 472);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t14, 0, 8);
    xsi_vlog_signed_minus(t14, 32, t3, 32, t2, 32);
    t5 = (t0 + 4664);
    xsi_vlogvar_wait_assign_value(t5, t14, 0, 0, 2, 0LL);
    xsi_set_current_line(191, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4504);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 32, 0LL);
    goto LAB26;

LAB30:    t15 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB31;

LAB32:    xsi_set_current_line(196, ng0);

LAB35:    xsi_set_current_line(200, ng0);
    t24 = (t0 + 4664);
    t25 = (t24 + 56U);
    t31 = *((char **)t25);
    t32 = ((char*)((ng5)));
    memset(t33, 0, 8);
    t34 = (t31 + 4);
    t35 = (t32 + 4);
    t36 = *((unsigned int *)t31);
    t37 = *((unsigned int *)t32);
    t38 = (t36 ^ t37);
    t39 = *((unsigned int *)t34);
    t40 = *((unsigned int *)t35);
    t41 = (t39 ^ t40);
    t42 = (t38 | t41);
    t43 = *((unsigned int *)t34);
    t44 = *((unsigned int *)t35);
    t45 = (t43 | t44);
    t46 = (~(t45));
    t47 = (t42 & t46);
    if (t47 != 0)
        goto LAB39;

LAB36:    if (t45 != 0)
        goto LAB38;

LAB37:    *((unsigned int *)t33) = 1;

LAB39:    t49 = (t33 + 4);
    t50 = *((unsigned int *)t49);
    t51 = (~(t50));
    t52 = *((unsigned int *)t33);
    t53 = (t52 & t51);
    t54 = (t53 != 0);
    if (t54 > 0)
        goto LAB40;

LAB41:    xsi_set_current_line(201, ng0);
    t2 = (t0 + 2504U);
    t3 = *((char **)t2);
    t2 = (t0 + 4184);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 32, 0LL);

LAB42:    xsi_set_current_line(203, ng0);
    t2 = (t0 + 4664);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = ((char*)((ng2)));
    memset(t14, 0, 8);
    t12 = (t5 + 4);
    t15 = (t11 + 4);
    t6 = *((unsigned int *)t5);
    t7 = *((unsigned int *)t11);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t12);
    t10 = *((unsigned int *)t15);
    t17 = (t9 ^ t10);
    t18 = (t8 | t17);
    t19 = *((unsigned int *)t12);
    t20 = *((unsigned int *)t15);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB46;

LAB43:    if (t21 != 0)
        goto LAB45;

LAB44:    *((unsigned int *)t14) = 1;

LAB46:    t24 = (t14 + 4);
    t26 = *((unsigned int *)t24);
    t27 = (~(t26));
    t28 = *((unsigned int *)t14);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB47;

LAB48:    xsi_set_current_line(209, ng0);
    t2 = (t0 + 4664);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = ((char*)((ng5)));
    memset(t14, 0, 8);
    xsi_vlog_unsigned_minus(t14, 32, t5, 2, t11, 32);
    t12 = (t0 + 4664);
    xsi_vlogvar_wait_assign_value(t12, t14, 0, 0, 2, 0LL);

LAB49:    goto LAB34;

LAB38:    t48 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t48) = 1;
    goto LAB39;

LAB40:    xsi_set_current_line(200, ng0);
    t55 = (t0 + 2504U);
    t56 = *((char **)t55);
    t55 = (t0 + 4024);
    xsi_vlogvar_wait_assign_value(t55, t56, 0, 0, 32, 0LL);
    goto LAB42;

LAB45:    t16 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB46;

LAB47:    xsi_set_current_line(204, ng0);

LAB50:    xsi_set_current_line(205, ng0);
    t25 = ((char*)((ng6)));
    t31 = (t0 + 4344);
    xsi_vlogvar_wait_assign_value(t31, t25, 0, 0, 3, 0LL);
    xsi_set_current_line(206, ng0);
    t2 = (t0 + 608);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t14, 0, 8);
    xsi_vlog_signed_minus(t14, 32, t3, 32, t2, 32);
    t5 = (t0 + 4824);
    xsi_vlogvar_wait_assign_value(t5, t14, 0, 0, 1, 0LL);
    goto LAB49;

LAB53:    t31 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB55;

LAB54:    *((unsigned int *)t14) = 1;
    goto LAB55;

LAB57:    xsi_set_current_line(212, ng0);

LAB60:    xsi_set_current_line(213, ng0);
    t34 = (t0 + 4184);
    t35 = (t34 + 56U);
    t48 = *((char **)t35);
    t49 = (t0 + 4024);
    xsi_vlogvar_wait_assign_value(t49, t48, 0, 0, 32, 0LL);
    xsi_set_current_line(214, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = (t0 + 4184);
    xsi_vlogvar_wait_assign_value(t11, t5, 0, 0, 32, 0LL);
    goto LAB59;

LAB62:    *((unsigned int *)t14) = 1;
    goto LAB63;

LAB64:    xsi_set_current_line(217, ng0);

LAB67:    xsi_set_current_line(218, ng0);
    t24 = (t0 + 4024);
    t25 = (t24 + 56U);
    t31 = *((char **)t25);
    t32 = (t0 + 4184);
    t34 = (t32 + 56U);
    t35 = *((char **)t34);
    memset(t33, 0, 8);
    xsi_vlog_unsigned_minus(t33, 32, t31, 32, t35, 32);
    t48 = (t0 + 4024);
    xsi_vlogvar_wait_assign_value(t48, t33, 0, 0, 32, 0LL);
    goto LAB66;

LAB71:    t24 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB72;

LAB73:    xsi_set_current_line(231, ng0);
    t31 = ((char*)((ng4)));
    t32 = (t0 + 4344);
    xsi_vlogvar_wait_assign_value(t32, t31, 0, 0, 3, 0LL);
    goto LAB75;

LAB78:    t12 = (t14 + 4);
    *((unsigned int *)t14) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB79;

LAB80:    xsi_set_current_line(233, ng0);
    t16 = (t0 + 4824);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    t31 = ((char*)((ng5)));
    memset(t33, 0, 8);
    xsi_vlog_unsigned_minus(t33, 32, t25, 1, t31, 32);
    t32 = (t0 + 4824);
    xsi_vlogvar_wait_assign_value(t32, t33, 0, 0, 1, 0LL);
    goto LAB82;

}


extern void work_m_15940190078727560531_3686640409_init()
{
	static char *pe[] = {(void *)Cont_168_0,(void *)Cont_169_1,(void *)Cont_171_2,(void *)Always_173_3};
	xsi_register_didat("work_m_15940190078727560531_3686640409", "isim/Testbench_isim_beh.exe.sim/work/m_15940190078727560531_3686640409.didat");
	xsi_register_executes(pe);
}
