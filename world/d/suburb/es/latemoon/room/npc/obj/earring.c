
#include <armor.h>
inherit HEAD;

void create()
{
        set_name( "����", ({ "earring" }) );
        set("long","����һ���ñ�ʯ�⴮�ɵ�����������\n");
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1500);
                set("material", "gold");
                set("armor_prop/armor", 1);
        set("wear_msg", "$N��$n�ó������ڶ����ϡ�\n");
        }
        setup();
}