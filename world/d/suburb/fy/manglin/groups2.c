inherit ROOM;
// 
// 


void create()
{
        set("short", "ç��֮��");
        set("long", @LONG
���ܹ������죬�����ܲ���Ũ�ܿ������Ҷ�ڱ��������ǳ���ʹ�˷ֲ���
��ҹ����������һ��ļž���ֻ�з紵�����ҵ�ɳɳ֮����ż��һ������Х��
�������ȷ�Ʈ�����ʡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"dummy2",
  "west" : __DIR__"dummy2",
  "north" : __DIR__"center2",

]));
        set("objects", ([
                __DIR__"npc/tiger" : 1,
                __DIR__"npc/wolf" : 2,
                __DIR__"npc/snake" : 1,
                __DIR__"npc/bear" : 1,
       ]) );

        setup();
replace_program(ROOM);
}