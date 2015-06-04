/*day   :20150602,3
 *Yusha
 *
 *writer:  Yusuke Kato
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include "file.h"

//#define printf print_story

int Yusha()
{
	int c;
	int iti;
	
	printf("\n半年前に復活した魔王によって、世界は滅びようとしていた。\n"
	            "そこで各国は、魔王討伐のために軍隊を向かわせたが、\n"
	            "魔王軍の前では無力であった。\n"
	            "何とかしなくてはと考えた国王は”伝説の勇者”を探し出し、\n"
	            "その者に魔王討伐を託すことにした。\n\n\n\n");
	
	printf("%s は目覚めた。窓から入ってくる太陽の光がまぶしい。\n"
	            "布団から出ると誰かが自分を呼ぶ声がする。\n\n\n", p.name);
		   
	printf("誰が呼んでいるか[選択]\n");
	
	printf("1: 母\n"
	       "2: 父\n"
	       "3: 愛猫のミケ\n"
	       "4: となりの山田さん\n");
	       
	scanf("%d", &iti);
	
	if (iti == 1) {
		printf("呼んでいるのは母のようだ。\n"
		       "母「朝ごはんできてるから、早く食べてよ」\n"
		       "テーブルの上にはおいしそうなパンとスープ、サラダがある。\n"
		       "いただきます、とさっそくスープを口に運ぶ。\n"
		       "一口食べた瞬間、激痛が体中を走る。\n"
		       "！！！！！ 毒だ ！！！！！\n");
	} else if (iti == 2) {
		printf("呼んでいるのは父のようだ。\n"
		       "父「まき割りを手伝ってくれないか」\n"
		       "まきを割るために家の裏に向かった。\n"
		       "いつものように斧を使ってまきを割る。\n"
		       "しかし、まきを割ろうとした瞬間、まきがはじけ飛ぶ！！\n"
		       "！！！！！ 破片が痛い ！！！！！\n");
	} else if (iti == 3) {
		printf("呼んでいるのは愛猫のミケのようだ。\n"
		       "ミケ「・・・・・・にゃー」\n"
		       "・・・・・・なごむ・・・・・\n");
	} else if (iti == 4) {
		printf("呼んでいるのはとなりの山田さんのようだ。\n"
			   "「こんにちは！！山田さん、どうしたんですか。\n"
			   " 山田さん・・・？ 黙ったままで、何かあったんですか。\n"
			   );
	}

	
	player_write(p);
	
	printf("Please any key.\n");
	c = fgetc(stdin);
	
	return;
 }