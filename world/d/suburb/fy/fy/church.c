inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
����Ľ������һ�񣬷����ر�ߣ��ɹ��Σ����滹�и��޴��ʮ�ּܡ�������
���������ĸ��񡣵����һЩ�𷢱��ۣ���������С��ʹ���������е�ʮ�ּ��϶�
��һ��ȫ����Ѫ���������������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"swind2",
  "north" : __DIR__"chjian",
]));
        set("objects", ([
        __DIR__"npc/priest" : 1,
                        ]) );

	set("no_fight",1);
		set("NONPC",1);
	set("no_magic",1);
        setup();
        replace_program(ROOM);
}