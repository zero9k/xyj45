// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�߲��г�");
  set ("long", @LONG

�߲��г�ΪһС�ճ��أ����϶���һЩ�ò�Ҷ��Ƥ֮���������
�������в��ٴ����۲˵�ũ������ʱҲ�ɼ�����λ��ũ���ŵ�
������������

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao75",
      ]));
  set("objects", ([
        __DIR__"npc/wei"   : 1,
      ]));

  setup();
}

