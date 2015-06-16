/*
 * Explanation : This game has created since 1 June.
 *
 * Title       : Happy Story
 * 
 * Writer      : Yusuke Kato
 *               Satosi Simada
 *               Peko_chan
 * 
 * Player      : izumi tyinko-beru
 *               Naoya Tarumi
 * 
 * Date        : June. 1,2,
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <stdarg.h>

#include "rpg.h"
#include "file.h"
#include "print_screen.h"

/* Global variable */
struct player p;

void main(void)
{
	int con;
	
start_game:
	
#ifdef WINDOWS
	system("cls");
#endif // WINDOWS
	printf("ゲームを開始します。\n");
	
	if(player_read(&p) != 0) {
make_char:
		make_charactor(&p);
		printf("キャラクター作成完了！\n");
	} else {
		printf("キャラクターデータを検出！\nロード中.......\n"
			"+----------------------+\n"
			"|レベル | %d\n"
			"|名前   | %s\n"
			"|職業   | %d\n"
			"|年齢   | %d\n"
			"|性別   | %d\n"
			"+----------------------+\n",
			p.level, p.name, p.job, p.age, p.sex);
		printf("このデータでプレイしますか？\n"
			"1: Yes, 0: No > ");
		scanf("%d", &con);
		if(!con) goto make_char;
	}
	
	system("cls");
	
	fflush(stdin);
	/* 職業によってストーリーを分岐 */
	switch(p.job) {
	case 1:
		Yusha();
		break;
	case 7:
		Fujiwara();
		break;
	default:
		printf("ストーリーのロードに失敗しました\n\n");
		break;
	}
	
	printf("どれかキーを押してください...");
	_getch();
	
#ifdef WINDOWS
	system("cls");
#endif // WINDOWS
	printf("続ける: 1\n");
	printf("やめる: 0\n");
	scanf("%d", &con);
	if(con == 1) goto start_game;
	
	return 0;
}
