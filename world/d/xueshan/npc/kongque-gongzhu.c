// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// kongque-gongzhu.c...weiqi, 97.09.15.

inherit NPC;

string get_ice(object me);
void do_drop(object ob);

void create()
{
   set_name("��ȸ����", ({"kongque gongzhu", "kongque", "gongzhu"}));
   set("title", "��������");
   set("gender", "Ů��" );
   set("age", 23);
   set("per", 21);

   set("long", "��λ��ȸ�����ǿ�ȸ������Ů������ȸ��������������Ѻ����ɽ��\n���ɴ�������һ�ִ���˵��ֶŮ�����������ʵ���и�Ů֮�顣\n");
   set("class", "yaomo");
   set("combat_exp", 800000);
   set("attitude", "peaceful");
   create_family("��ѩɽ", 2, "����");
   set_skill("unarmed", 70);
   set_skill("cuixin-zhang", 70);
   set_skill("dodge", 90);
   set_skill("xiaoyaoyou", 120);
   set_skill("parry", 70);
   set_skill("blade", 90);
   set_skill("bingpo-blade", 120);
   set_skill("force", 90);   
   set_skill("ningxie-force", 90);
   set_skill("literate", 90);
   set_skill("spells", 80);
   set_skill("dengxian-dafa", 90);
   map_skill("spells", "dengxian-dafa");
   map_skill("force", "ningxie-force");
   map_skill("unarmed", "cuixin-zhang");
   map_skill("blade", "bingpo-blade");
   map_skill("dodge", "xiaoyaoyou");

   set("max_kee", 1000);
   set("max_sen", 600);
   set("force", 1600);
   set("max_force", 800);
   set("mana", 1000);
   set("max_mana", 500);   
   set("force_factor", 60);
   set("mana_factor", 25);

        set("eff_dx", -200000);
        set("nkgain", 400);

   setup();
   carry_object("/d/obj/cloth/skirt")->wear();
   carry_object("/d/obj/cloth/shoes")->wear();
   carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{

   if( (string)ob->query("family/family_name")=="��ѩɽ" ){
     if( (int)ob->query("family/generation") < 2  ){
        command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
     }
     else if( (int)ob->query("family/generation") ==2  ){
        command("say �����" + RANK_D->query_rude(ob) + "������ǲ��ҹ��������ˣ�\n");
     }
     else if( (int)ob->query("family/generation") ==3  ){
        command("blush ");
        command("say �����" + RANK_D->query_rude(ob) + "����������Ը�ģ��ɲ�������ǽ��...\n");
        command("recruit " + ob->query("id") );
     }
     else {
        if( (int)ob->query("combat_exp") >= 50000 ){
          command(":) ");
          command("say �ã�" + RANK_D->query_respect(ob) + "��Ȼ�������¾͵ø����������ɲ���͵����\n");
          command("recruit " + ob->query("id") );
        }
        else {
          command("say �㻹�������ģ���ѻ���������Űɡ�\n");
        }
     }
   }

   else{
     command("hmm");
     command("say ��λ" + RANK_D->query_respect(ob) + "���㻹�������ģ���ѻ�����������ɡ�\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yaomo");
}

void init()
{       
   object ob, me;

   me = this_player();

   ::init();

   set("chat_chance", 10);
   set("inquiry", ([
     "name" : "�������㡣\n",
     "here" : "�㻹û����...������������\n", 
     "������" : (: get_ice :),
     "��������" : (: get_ice :),
     "����" : (: get_ice :),
    ]) );

   set("chat_msg", ({
     "��ȸ����̾�˿�����\n",   
     "��ȸ���������������Ҳ��֪�������Ĳ�ʲôʱ���ܺá�\n",
     "��ȸ����������ü������˵���ֲ���ů��������ô����Ϊ�������������أ�\n",
     "��ȸ������̾�˿�����������ô�û����ɣ��϶������ʲô...��ô�໨�ݻ�����ȥҲû��ѽ��\n",
     "��ȸ���������������������Ū�������������´��²����ˡ�\n",        
   }) );

   if ( ((string)me->query("gender") == "����") && ((int)me->query("per") > 25) && ((int)me->query("combat_exp") < 10000) && (random(3) >1) )
   {
     remove_call_out("greeting");
     call_out("greeting", 1, me);
   }

}

void greeting(object me)
{
   if( !me || environment(me) != environment() ) return;

   switch( random(1) ) {
     case 0:
        command("say �ø������ӣ�\n");
        command("say ��ϧ�Ǹ��廨��ͷ...\n");
        command("kick " + me->query("id"));
        break;
   }
}

string get_ice(object me)
{
   object env;

   me = this_player();
   env = environment(this_object());

   if( me->query_temp("ice_given") && (string)env->query("short")=="Сľ��" && (string)me->query("family/family_name")=="��ѩɽ")
   {
     me->delete_temp("ice_given");
     message_vision("��ȸ������$N��������˵�˼��仰��\n", me);
     write("��ȸ���������������Ȼ����������������ȥ��\n");
     message_vision("ֻ����ȸ�������������ӵ��°���һ����\n", me);
     env->open_down();
     return "����ʱ��һ��ǽ���ɡ�\n";
   }
   else
   {
     return "�������������Ҹ������Ҹ������Ǵ���������\n";
   }
}

int accept_object(object me, object ob)
{
   if ( ((string)ob->query("id") != "lan bingkuai") && 
     ((string)ob->query("id") != "shuangse bing") ) 
   {
     command("say ȥ��ȥ��ȥ����������ҹ������ң�\n");
     //command("drop " + ob->query("id"));
     //this does not work due to time problem...
     //have to use call_out().
     call_out("do_drop", 1, ob);
     return 1;
   }

   else {
     command("ah ");
     command("jump ");
     command("say ��λ" + RANK_D->query_respect(me) + "���������ˣ�\n");
     command("whisper " + me->query("id")+" ���Ҹ�����һ�������ܣ��Ҹ������ڸ����Ͳ��ڱ���������ú�����������Ҫ���ֺ�����\n");
     me->set_temp("ice_given", 1);
            return 1;
   }
}

void do_drop(object ob)
{
   command("drop "+ob->query("id"));
}