// sword:__DIR__"obj/sword.c" ����һ��

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("����",({"sword"}));
	set_weight(5500);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "��");
		set("long", "����һ����ͨ��������������ûʲô���ء�\n");
	    	set("value", 420);
		set("material", "iron");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }
	init_sword(13);
	setup();
}
