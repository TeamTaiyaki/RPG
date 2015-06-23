
struct player {
	int level;
	char name[1024];
	int job;
	int sex;
	int age;
	int money;
};

int player_write(struct player p);
int player_read(struct player *);

int Yusha();
int Fujiwara();
int make_charactor(struct player *p);
