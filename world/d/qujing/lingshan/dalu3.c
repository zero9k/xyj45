// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

��·���ߣ������������ݣ��Űأ����ɡ���Ȼһ��������أ�
��������ͬ����ʱ�ɼ�·�����˻���ͣ��·���޵������Ǳ�Ŀ
�о���

LONG);

  set("exits", ([
        "west"   : __DIR__"dalu2",
        "east"   : "/d/qujing/tianzhu/dalu1",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 1+random(3),
      ]));
  set("outdoors", __DIR__);

  setup();
}


