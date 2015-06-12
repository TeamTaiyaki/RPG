/*
 * Creation date : 2 June 2015
 * Last updated  : 12 June 2015
 * Filename      : Yusha.c
 *
 * Author(story) : Yusuke Kato
 *
 * ========================================
 *       Episode 1: 勇者の旅立ち
 * ========================================
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "file.h"
#include "print_screen.h"

//#define printf print_story

extern struct player p;

int Yusha(void)
{
	int c;
	int a;
	int b;
	
	//PROLOGUE
	
	
	
	//c = fgetc(stdin);
	//Sleep(2000);
	
	system("cls");
	printf("\n"
	       "      ================================= \n"
	       "           Episode 1: 勇者の旅立ち      \n"
	       "      =================================\n");
	   
	c = fgetc(stdin);   
	//fflush(stdin);
	
	printf( "\n---------------  世界  ---------------\n\n\n"
			"半年前に復活した魔王によって、世界は滅びようとしていた。\n"
			"そこで各国は、魔王討伐のために軍隊を向かわせたが、\n"
			"魔王軍の前では無力であった。\n"
			"何とかしなくてはと考えた国王は”伝説の勇者”を探し出し、\n"
			"その者に魔王討伐を託すことにした。\n\n\n"
			"----------------------------------------------\n\n\n\n\n\n");
	
	c = fgetc(stdin);
	//fflush(stdin);
	
	printf("\n\n\n1 - 1\n\n\n ");
	
	system("cls");
	printf("\n\n\n< 1 - 1 > 物語の始まり");
	printf( "\n\n\n- - - - - - パラパッパパ村の %s の家 - - - - - -\n\n"
			"\n %s は目が覚めた。窓から入ってくる太陽の光がまぶしい。\n"
			"ベットから降りて、ひとつ伸びをする。\n"
			"と、そのとき、誰かが %s を呼ぶ声が聞こえた......\n\n",p.name, p.name, p.name);
	
	printf("誰が呼んでいるか[選択]\n");
	
	printf("1: 母\n"
	       "2: 父\n"
	       "3: 愛猫のミケ\n"
	       "4: となりの山田さん\n");
	
	scanf("%d",&a);
	
	if (a == 1) {
		system("cls");
		printf("\n呼んでいるのは母のようだ。\n"
		       "母「朝ごはんできてるから、早く食べてよ」\n"
		       "テーブルの上にはおいしそうなパンとスープ、サラダがある。\n"
		       "いただきます、とさっそくスープを口に運ぶ。\n"
		       "一口食べた瞬間、激痛が体中を走る。\n"
		       "！！！！！ 毒だ！！！！！\n");
		       c = fgetc(stdin);
	} else if (a == 2) {
		system("cls");
		printf("\n呼んでいるのは父のようだ。\n"
		       "父「まき割りを手伝ってくれないか」\n"
		       "まきを割るために家の裏に向かった。\n"
		       "いつものように斧を使ってまきを割る。\n"
		       "しかし、まきを割ろうとした瞬間、まきがはじけ飛ぶ！！\n"
		       "！！！！！ 破片が痛い ！！！！！\n");
		       c = fgetc(stdin);
	} else if (a == 3) {
		system("cls");
		printf("\n呼んでいるのは愛猫のミケのようだ。\n"
		       "ミケ「・・・・・・にゃー」\n"
		       "・・・・・・なごむ・・・・・\n");
		       c = fgetc(stdin);
	} else if (a == 4) {
		system("cls");
		printf("\n呼んでいるのはとなりの山田さんのようだ。\n"
			   "%s「こんにちは！！山田さん、どうしたんですか。\n"
			   " 山田さん・・・？ 黙ったままで、何かあったんですか?」\n"
			   "山田さん「・・・・・・フフフ・・・フハハハハハハハハハハハッ！！！」\n"
			   "%s 「なんですか！？ どうしたんですか！？！？」\n"
			   "山田さん「私が魔王だ！！！！！！！！」\n"
			   "%s 「な、なんだって！？！？」\n"
			   "山田さん「世界はもらっていくぞ！！！！！」\n"
			   "%s 「そうはさせないっ！！！！！」\n\n\n\n"
			   "！！！山田さんとの戦闘に突入！！！\n",p.name ,p.name, p.name, p.name);
			   c = fgetc(stdin);
	}
	//2 - 2
	
	c = fgetc(stdin);
	
	system("cls");
	printf("\n\nタケオ「おーい！！ 起きてるかーーっ！！！」\n"
	       "親友のタケオの呼ぶ声がする。こんなに朝早くに来るなんて珍しい。\n"
	       "タケオ「知ってるか！！！魔王を倒せるのは”伝説の勇者”だけなんだってよ！！！\n"
	       "        ”伝説の勇者”って、%s のことだよな！？\n", p.name);
	
	printf("あなたの返事は？ [選択]\n\n\n");
	
	printf("1,もちろん、そうだよ。\n"
	       "2,そんなわけない。\n"
	       "3,”伝説の勇者”、それはタケオ、お前のことだ！！！\n");
	
	scanf("%d",&b);
	
	if (b == 1) {
		system("cls");
		printf("タケオ「やっぱりそうか。いや、ずっと前から分かっていたんだ。\n"
		       "	お前が勇者だってことはよ。\n"
		       "	だって俺も勇者だからな！！！」\n"
		       "%s  「なんだって！？！？」\n"
		       "タケオ「勇者は一人だけでいい・・・・・・\n"
		       "	つまり俺かお前か、どちらかが勇者として魔王を討ちに行く。\n"
		       "	だからどちらが本当の勇者か、決めなきゃなんねぇ。\n"
		       "	勝負だ！！ %s！！\n",p.name ,p.name);
	} else if (b == 2) {
		
	} else {
		
	}
	
	player_write(p);
	
	printf("Please Enter key\n");
	c = fgetc(stdin);
	
	return 0;
}