#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "rpg.h"
#include "file.h"

int make_charactor(struct player *p)
{
	char buf[1024];
	char *name = p->name;
	int *age = &(p->age);
	int *sex = &(p->sex);
	int *job = &(p->job);
	
	fflush(stdin);
	
	// 所持金を 0 に初期化
	p->money = 0;
	// レベルを 1 に初期化
	p->level = 1;
	
	/* 名前の入力 */
	printf("キャラクターを作成します\n");
	printf("名前を教えてね♪ > ");
	fgets(buf, sizeof(buf), stdin);
	strncpy(name, buf, strlen(buf) - 1);
	name[strlen(buf) -1] = '\0';

	printf("%s かぁ～!!! いい名前だね♪\n", name);

	/* 年齢の入力 */
	for(;;) {
		printf("何歳なのっっ♪ > ");
		fgets(buf, sizeof(buf), stdin);
		*age = atoi(buf);
		if(*age > 0 && *age < 130) break;
		printf("いやいや、%dとかありえないでしょー\n秘密にするから私にだけ教えて！\n", *age);
	}

	printf("%d歳なんだー\n", *age);
	
	/* 性別の入力 */
	for(;;) {
		printf("どっちかなぁ？\n 1:男 2:女の子 > ");
		fgets(buf, sizeof(buf), stdin);
		*sex = atoi(buf);
		if(*sex == 1 || *sex == 2) break;
		printf("ごめんね！よく聞こえなかった、もう一度教えて！！\n");
	}

	/* 職業の入力 */
	for(;;) {
		printf("職業をえらんで\n"
			"\t1: 勇者\n"
			"\t2: 魔王（シューベルト作）\n"
			"\t3: 徳川家光\n"
			"\t4: 学生（のふりをしたスパイ）\n"
			"\t5: 勇者に憧れたナイト\n"
			"\t6: たこ焼き職人\n"
			"\t7: スーパーハッカー藤原（スパコン８４台所持）\n"
			"\t8: 狂気な目をした鳥（以下略）\n"
			"\t9: たこ焼き（そのもの）\n"
			"\t10: 親の脛をかじり続けて早２４年の独身男性（ps.童貞）。\n"
			"\t11: 会社員（課長になりたいと願い続けて１３年）のようなニート\n"
			"\t12: 脱サラしてコンビニの店長になったけど病気を患ってやめて、今はニート\n"
			"\t0: 松佐(さまつ)川 航\n");
		fgets(buf, sizeof(buf), stdin);
		*job = atoi(buf);
		if(*job >= 0 && *job <= 12) break;
		printf("選択は無効です(^ ^;;\n再入力してください\n");
	}

	player_write(*p);
	
	return 0;
}
