/*
 * Date: 2, June
 * Author: Yosida
 */

#include <stdio.h>
#include "file.h"
#include "print_screen.h"

extern struct player p;

int Fujiwara(void)
{
	int i;
	int a;
	
	fflush(stdin);
	
	print_story("hahaha....よくぞここまで来れたな...\n");
	print_story("時代は２０ｘｘ年。私はMR.MAXの元で８４８年間修業を積んだ。\n");
	print_story("こんな私を倒せるかな？？ さあ、始めよう.....\n");
	
	print_story("\t1:スパコンを差し入れる。\n");
	print_story("\t２:謝る。\n");
	print_story("\t３:喧嘩を売る。\n");
	
	scanf("%d", &a);
	if(a == 1){ /* スパコンを差し入れる */
		print_story("何台だ？ 台数によっては生かしておいてやろう。\n");
		print_story("台数を入力しよう！！ >\n");
		scanf("%d", &i);
		
		if(i >= 82) {
			print_story("お前なかなかわかっているな。今回は見逃してやろう。\n");
		} else {
			print_story("ははは、冗談はその薄汚く気持ちの悪い顔だけにしろ。\n");
			print_story("藤原は薄笑いを浮かべながらEnter Keyを噛みしめるように押した....\n"
				"to be continude.....\n");
			return 0;
		}
	} else if(a == 2) { /* 謝る */
		
	} else if(a == 3) { /* 喧嘩を売る */
		
	}
	return 0;
}