#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

int main(void)
{
	struct s_player **players;

	players = genRandomPlayers(10); //if param == 0, the length of the list will be random between 1 and 1.000

	/*-------------------
	launch your test here
	--------------------*/
	printPlayers(players);
	printf("doing the merge sort...\n");
	players = mergeSort(players);
	printPlayers(players);

	return (0);
}


// Function used for the test
// Don't go further :)

void printPlayers(struct s_player **players)
{
	printf("⭐  LEADER BOARD ⭐ \n");
	for (int i = 0; players[i]; i++) {
		printf("[%s] %d: %s with %d\n", players[i]->timeStamp, i + 1, players[i]->name, players[i]->score);
	}
}

struct s_player **genRandomPlayers(int n){
	struct s_player **players;
	char *names[] = { "Beatriz Leroy", "Fernando Fradin", "Claud Lannoy", "Heriberto Franceschi", "Joleen Olsen", "Zula Inesta", "Keturah Bidault", "Helaine Weibel", "Elba Corre", "Terisa Uberti", "Yoshie Taupin", "Hannah Hamza", "Enid Aubree", "Kimberlie Claudel", "Clora Tisserand", "Sadie Urbanek", "Pearlene Virot", "Monique Napolitano", "Madelene Ibouroi", "Richelle Arnal", "Mathilde Bernard", "Lolita Delamare", "Irina Oberle", "Delila Kayser", "Catrina Iglesias", "Louis Barbara", "Michel Willerval", "Freda Quennesson", "Lilli Quersin", "Marlene Nelson", "Coreen Triquet", "Lyda Gombert", "Cherilyn Zemouri", "Shawnee Kanza", "Pasty Witkowski", "Omar Theron", "Wilhelmina Valles", "Valery Stein", "Angelic Hell", "Bobby Ducrocq", "Holley Gillot", "Samatha Rogier", "Vina Wasser", "Lita Benali", "Jessica Habib", "Clelia Usan", "Marquitta Quetier", "Lynetta Kevin", "Alica Wallerand", "Stephaine Zoro", "Perla Julienne", "Alease Damiens", "Jeannie Erdmann", "Stella Abed", "Iraida Collet", "Josette Wasser", "Pasquale Khoury", "Gudrun Hagege", "Yee Der", "Jae Techer", "Lizbeth Vallon", "Kamilah Garde", "Van Queiroz", "Keena Grimaud", "Corinne Ordonneau", "Candyce Duthoit", "Claris Isard", "Annamaria Pochon", "Isabel Guen", "Misha Odiot", "Natalie Stoll", "Ralph Mike", "Josefa Taha", "Brandon Issert", "Meredith Uhmann", "Lilliana Naas", "Toi Nectoux", "Leeanne Espinasse", "Marcene Montana", "Maxine Lecerf", "Zachery Erdmann", "Nena Jourdan", "Waneta Gerardin", "Penney Moro", "Amelia Karam", "Mei Onfray", "Elodia Cauvin", "Jeanne Exposito", "Ladawn Uzan", "Lorina Farmer", "Rosalyn Westrelin", "Harriet Undostres", "Adrianne Guilloux", "Man Vassal", "Tamesha Soriano", "Logan Zurita", "Kathlyn Eschenbrenner", "Laverna Rousselot", "Manda Dore", "Shelba Gloaguen" };
	char *timeStamps[] = {"2015-11-03 07:41:39", "2015-11-04 02:08:49", "2015-11-04 15:56:55", "2015-11-05 06:01:25", "2015-11-06 03:36:06", "2015-11-06 13:33:54", "2015-11-06 14:40:50", "2015-11-07 00:09:03", "2015-11-07 04:30:32", "2015-11-08 01:45:24", "2015-11-08 16:17:27", "2015-11-08 16:55:26", "2015-11-08 23:52:19", "2015-11-09 03:28:58", "2015-11-09 06:44:51", "2015-11-09 12:07:23", "2015-11-09 18:35:55", "2015-11-10 08:19:30", "2015-11-11 04:33:11", "2015-11-11 16:56:34", "2015-11-11 17:05:22", "2015-11-12 00:33:02", "2015-11-12 01:05:14", "2015-11-12 19:04:26", "2015-11-13 10:38:53", "2015-11-14 10:04:16", "2015-11-15 05:31:34", "2015-11-15 08:08:44", "2015-11-15 12:13:49", "2015-11-15 15:18:05", "2015-11-16 07:03:28", "2015-11-17 04:06:18", "2015-11-17 18:29:01", "2015-11-18 11:24:21", "2015-11-19 00:47:21", "2015-11-19 10:00:13", "2015-11-19 19:07:24", "2015-11-20 16:53:47", "2015-11-21 10:37:25", "2015-11-21 22:18:50", "2015-11-22 18:21:03", "2015-11-23 09:43:56", "2015-11-24 07:17:28", "2015-11-24 09:29:05", "2015-11-25 01:51:48", "2015-11-25 19:14:49", "2015-11-26 00:37:51", "2015-11-26 14:17:24", "2015-11-27 10:08:54", "2015-11-27 22:41:17", "2015-11-28 07:40:21", "2015-11-28 12:50:37", "2015-11-29 06:02:43", "2015-11-29 20:51:51", "2015-11-30 16:38:28", "2015-12-01 10:51:45", "2015-12-01 15:49:17", "2015-12-02 00:03:39", "2015-12-02 15:15:19", "2015-12-03 14:55:16", "2015-12-04 10:54:22", "2015-12-05 08:57:10", "2015-12-06 05:04:02", "2015-12-06 21:45:31", "2015-12-06 23:56:10", "2015-12-07 20:16:20", "2015-12-08 10:21:06", "2015-12-08 23:54:14", "2015-12-09 02:38:06", "2015-12-09 13:15:06", "2015-12-09 18:19:07", "2015-12-10 16:21:16", "2015-12-10 17:50:35", "2015-12-11 15:09:22", "2015-12-11 20:35:57", "2015-12-12 08:52:22", "2015-12-12 15:34:50", "2015-12-12 23:03:05", "2015-12-13 00:10:17", "2015-12-13 06:47:01", "2015-12-14 05:29:00", "2015-12-14 18:52:40", "2015-12-15 12:11:35", "2015-12-16 11:56:47", "2015-12-17 04:42:28", "2015-12-17 20:30:41", "2015-12-18 13:34:41", "2015-12-18 20:25:13", "2015-12-19 04:39:34", "2015-12-19 04:56:03", "2015-12-19 21:19:36", "2015-12-20 05:21:28", "2015-12-20 12:25:56", "2015-12-21 02:24:16", "2015-12-21 19:22:38", "2015-12-22 03:39:11", "2015-12-22 04:51:32", "2015-12-22 10:19:29", "2015-12-22 15:37:32", "2015-12-22 21:20:52", "2015-12-23 14:29:56", "2015-12-23 18:48:50", "2015-12-24 07:49:06", "2015-12-24 13:06:47", "2015-12-25 02:39:11", "2015-12-25 12:09:42", "2015-12-25 15:59:21", "2015-12-25 20:01:31", "2015-12-25 22:16:27", "2015-12-26 08:53:18", "2015-12-26 16:55:08", "2015-12-26 20:49:06", "2015-12-27 13:14:10", "2015-12-27 15:07:33", "2015-12-27 16:08:22", "2015-12-28 08:42:11", "2015-12-29 00:17:03", "2015-12-29 04:45:21", "2015-12-29 13:45:54", "2015-12-30 11:18:23", "2015-12-31 02:11:25", "2015-12-31 19:31:51", "2016-01-01 09:15:42", "2016-01-02 00:53:38", "2016-01-02 09:16:45", "2016-01-02 20:52:59", "2016-01-03 18:01:26", "2016-01-04 08:51:09", "2016-01-05 05:08:45", "2016-01-06 02:44:48", "2016-01-06 23:44:16", "2016-01-07 20:44:13", "2016-01-08 20:01:53", "2016-01-09 11:46:53", "2016-01-10 03:09:19", "2016-01-11 01:33:21", "2016-01-11 23:37:00", "2016-01-12 09:21:45", "2016-01-13 05:50:57", "2016-01-13 20:54:13", "2016-01-14 17:31:23", "2016-01-15 11:43:25", "2016-01-15 16:17:19", "2016-01-16 12:52:35", "2016-01-17 03:52:38", "2016-01-17 18:55:38", "2016-01-18 05:47:58", "2016-01-19 05:02:10", "2016-01-19 15:09:08", "2016-01-20 15:00:43", "2016-01-20 19:35:09", "2016-01-20 20:17:36", "2016-01-21 12:51:11", "2016-01-22 10:54:46", "2016-01-22 13:13:53", "2016-01-23 11:51:13", "2016-01-24 08:15:55", "2016-01-24 09:48:09", "2016-01-25 00:04:57", "2016-01-25 14:30:03", "2016-01-26 06:40:25", "2016-01-26 07:11:30", "2016-01-27 05:40:25", "2016-01-27 22:52:25", "2016-01-28 05:54:20", "2016-01-29 00:09:30", "2016-01-29 07:02:53", "2016-01-30 05:03:54", "2016-01-30 09:56:59", "2016-01-30 15:01:34", "2016-01-30 23:40:27", "2016-01-31 15:08:42", "2016-02-01 03:54:40", "2016-02-01 08:24:38", "2016-02-01 18:23:32", "2016-02-02 18:02:23", "2016-02-03 10:15:19", "2016-02-03 18:44:20", "2016-02-04 03:47:17", "2016-02-04 04:23:17", "2016-02-04 12:10:31", "2016-02-05 11:25:05", "2016-02-06 09:55:59", "2016-02-07 06:11:23", "2016-02-07 13:49:36", "2016-02-07 20:37:58", "2016-02-08 13:45:46", "2016-02-09 00:12:56", "2016-02-09 18:23:34", "2016-02-10 10:54:43", "2016-02-10 21:03:44", "2016-02-11 17:14:23", "2016-02-12 13:32:19", "2016-02-12 23:15:53", "2016-02-13 01:33:06", "2016-02-13 21:34:44", "2016-02-14 14:26:36", "2016-02-14 17:14:25", "2016-02-15 07:32:38", "2016-02-16 04:20:17", "2016-02-17 03:26:18", "2016-02-17 22:55:47", "2016-02-18 12:35:15", "2016-02-19 02:46:13", "2016-02-19 06:40:02", "2016-02-19 12:55:30", "2016-02-19 17:51:04", "2016-02-19 22:41:33", "2016-02-20 10:06:11", "2016-02-21 04:31:01", "2016-02-22 01:26:55", "2016-02-22 14:59:03", "2016-02-23 13:02:05", "2016-02-23 22:40:48", "2016-02-24 15:42:59", "2016-02-25 11:41:09", "2016-02-25 18:12:39", "2016-02-26 03:56:35", "2016-02-26 09:22:08", "2016-02-27 01:54:37", "2016-02-27 15:45:45", "2016-02-27 22:58:26", "2016-02-28 13:37:39", "2016-02-28 14:54:17", "2016-02-29 14:09:24", "2016-03-01 00:11:26", "2016-03-01 05:44:43", "2016-03-01 10:05:48", "2016-03-01 18:03:49", "2016-03-01 18:12:21", "2016-03-01 21:26:17", "2016-03-02 02:51:38", "2016-03-02 12:30:32", "2016-03-02 19:19:33", "2016-03-03 10:34:29", "2016-03-03 21:53:27", "2016-03-04 06:57:40", "2016-03-04 18:20:06", "2016-03-05 09:44:47", "2016-03-05 20:03:18", "2016-03-06 02:49:52", "2016-03-06 14:59:34", "2016-03-07 05:33:22", "2016-03-07 07:27:30", "2016-03-07 15:09:37", "2016-03-08 06:27:28", "2016-03-08 06:39:19", "2016-03-08 21:55:23", "2016-03-09 14:49:36", "2016-03-10 13:44:45", "2016-03-11 01:53:47", "2016-03-12 01:08:45", "2016-03-12 17:24:02", "2016-03-13 03:19:57", "2016-03-13 12:24:26", "2016-03-13 16:27:53", "2016-03-14 03:35:44", "2016-03-15 01:17:17", "2016-03-15 12:32:14", "2016-03-16 01:25:06", "2016-03-16 01:55:41", "2016-03-16 10:55:05", "2016-03-17 03:09:45", "2016-03-17 07:04:50", "2016-03-17 19:44:05", "2016-03-18 17:49:15", "2016-03-19 16:24:13", "2016-03-20 12:44:46", "2016-03-20 23:36:21", "2016-03-21 05:56:34", "2016-03-22 00:24:16", "2016-03-22 10:05:45", "2016-03-23 05:54:34", "2016-03-24 00:01:43", "2016-03-24 09:25:52", "2016-03-24 22:20:00", "2016-03-24 23:53:18", "2016-03-25 07:02:11", "2016-03-25 07:24:56", "2016-03-25 23:47:41", "2016-03-26 05:03:30", "2016-03-26 15:34:30", "2016-03-27 03:58:55", "2016-03-27 11:30:18", "2016-03-27 23:39:23", "2016-03-28 23:31:10", "2016-03-29 14:01:01", "2016-03-29 20:00:09", "2016-03-30 15:08:39", "2016-03-30 16:13:33", "2016-03-31 04:09:37", "2016-03-31 07:29:02", "2016-03-31 13:07:02", "2016-04-01 10:33:24", "2016-04-01 13:42:18", "2016-04-01 22:00:23", "2016-04-02 12:52:34", "2016-04-02 22:47:59", "2016-04-03 15:48:40", "2016-04-04 13:39:28", "2016-04-05 07:35:35", "2016-04-05 13:06:06", "2016-04-05 16:08:06", "2016-04-05 22:39:31", "2016-04-06 17:02:34", "2016-04-06 19:23:03", "2016-04-06 22:25:03", "2016-04-07 01:54:48", "2016-04-07 05:27:30", "2016-04-07 18:36:25", "2016-04-08 13:29:44", "2016-04-08 14:14:37", "2016-04-09 10:04:06", "2016-04-10 01:19:42", "2016-04-10 05:36:54", "2016-04-11 02:17:47", "2016-04-11 19:57:41", "2016-04-12 06:29:24", "2016-04-12 11:59:34", "2016-04-13 03:22:09", "2016-04-13 09:16:41", "2016-04-13 17:46:52", "2016-04-14 09:19:31", "2016-04-15 01:41:22", "2016-04-15 13:56:17", "2016-04-16 09:29:30", "2016-04-16 11:31:44", "2016-04-16 13:52:08", "2016-04-17 01:16:05", "2016-04-17 23:28:21", "2016-04-18 01:23:36", "2016-04-18 18:52:32", "2016-04-18 23:22:48", "2016-04-19 07:46:36", "2016-04-19 18:43:42", "2016-04-20 11:14:36", "2016-04-20 11:27:05", "2016-04-21 09:29:59", "2016-04-22 08:52:10", "2016-04-23 00:46:41", "2016-04-23 11:50:00", "2016-04-24 10:08:44", "2016-04-24 19:51:31", "2016-04-25 14:08:11", "2016-04-25 21:55:29", "2016-04-25 22:15:33", "2016-04-25 23:56:56", "2016-04-26 11:06:45", "2016-04-27 04:57:27", "2016-04-27 21:07:10", "2016-04-28 19:12:40", "2016-04-29 19:12:14", "2016-04-30 09:05:28", "2016-04-30 13:13:00", "2016-05-01 01:27:28", "2016-05-01 15:59:28", "2016-05-02 11:59:12", "2016-05-03 04:12:01", "2016-05-03 16:27:01", "2016-05-04 15:06:54", "2016-05-05 07:08:23", "2016-05-06 02:51:03", "2016-05-06 12:16:50", "2016-05-07 00:43:58", "2016-05-07 23:46:14", "2016-05-08 00:10:28", "2016-05-08 22:44:49", "2016-05-09 02:10:25", "2016-05-09 07:16:10", "2016-05-10 02:01:48", "2016-05-10 03:46:31", "2016-05-10 04:09:59", "2016-05-10 15:04:30", "2016-05-10 17:36:13", "2016-05-11 10:55:13", "2016-05-11 13:29:48", "2016-05-12 01:28:34", "2016-05-12 09:17:42", "2016-05-13 03:22:50", "2016-05-13 09:44:20", "2016-05-14 00:44:57", "2016-05-14 11:03:25", "2016-05-15 00:55:20", "2016-05-15 05:35:31", "2016-05-15 16:37:15", "2016-05-16 02:56:01", "2016-05-16 16:50:30", "2016-05-17 10:01:37", "2016-05-17 21:37:13", "2016-05-18 05:01:03", "2016-05-18 07:46:51", "2016-05-19 00:20:42", "2016-05-19 13:25:13", "2016-05-19 16:31:31", "2016-05-20 00:39:47", "2016-05-20 09:52:16", "2016-05-21 01:32:40", "2016-05-21 05:56:33", "2016-05-21 19:23:08", "2016-05-22 11:45:30", "2016-05-22 13:40:41", "2016-05-23 06:24:34", "2016-05-23 22:18:57", "2016-05-24 01:46:12", "2016-05-24 06:31:53", "2016-05-24 18:59:52", "2016-05-25 11:54:27", "2016-05-26 09:23:31", "2016-05-27 02:06:25", "2016-05-27 07:42:09", "2016-05-27 23:10:14", "2016-05-28 02:38:27", "2016-05-28 03:37:16", "2016-05-29 00:32:05", "2016-05-29 06:00:49", "2016-05-29 18:51:06", "2016-05-30 08:45:43", "2016-05-30 19:14:06", "2016-05-31 11:20:53", "2016-06-01 01:27:36", "2016-06-01 07:14:30", "2016-06-02 01:10:11", "2016-06-02 02:34:53", "2016-06-02 14:39:43", "2016-06-03 00:45:31", "2016-06-03 14:49:41", "2016-06-03 23:20:17", "2016-06-04 10:03:39", "2016-06-04 20:17:08", "2016-06-05 13:00:39", "2016-06-06 06:57:30", "2016-06-07 06:13:54", "2016-06-07 10:59:35", "2016-06-07 16:36:26", "2016-06-07 21:39:12", "2016-06-08 02:03:22", "2016-06-08 17:47:10", "2016-06-09 11:00:29", "2016-06-10 00:21:23", "2016-06-10 18:41:54", "2016-06-11 18:34:27", "2016-06-12 12:49:07", "2016-06-13 08:08:53", "2016-06-13 15:55:40", "2016-06-14 15:33:28", "2016-06-15 12:32:15", "2016-06-15 20:28:58", "2016-06-16 04:11:02", "2016-06-16 23:50:04", "2016-06-17 22:46:55", "2016-06-18 07:02:12", "2016-06-18 20:28:34", "2016-06-19 10:10:58", "2016-06-19 22:56:46", "2016-06-20 02:03:20", "2016-06-20 17:41:57", "2016-06-21 02:34:46", "2016-06-21 23:16:06", "2016-06-22 21:20:43", "2016-06-23 18:51:59", "2016-06-24 05:10:04", "2016-06-24 05:58:26", "2016-06-24 22:51:22", "2016-06-25 05:20:29", "2016-06-25 13:55:56", "2016-06-25 18:22:21", "2016-06-26 08:03:14", "2016-06-26 10:27:18", "2016-06-26 16:33:15", "2016-06-27 00:13:57", "2016-06-27 15:26:28", "2016-06-28 01:30:40", "2016-06-28 04:25:56", "2016-06-28 20:03:40", "2016-06-29 01:00:21", "2016-06-29 01:30:28", "2016-06-29 21:53:29", "2016-06-30 08:57:40", "2016-06-30 11:36:53", "2016-07-01 07:49:01", "2016-07-01 13:08:23", "2016-07-02 02:59:15", "2016-07-03 00:28:47", "2016-07-03 05:47:58", "2016-07-03 17:47:16", "2016-07-04 15:48:43", "2016-07-04 22:37:37", "2016-07-05 08:20:58", "2016-07-06 04:21:49", "2016-07-06 15:25:28", "2016-07-06 23:58:13", "2016-07-07 23:40:44", "2016-07-08 11:41:57", "2016-07-08 12:51:48", "2016-07-08 14:28:09", "2016-07-09 02:15:57", "2016-07-09 06:16:40", "2016-07-09 19:06:02", "2016-07-10 07:40:28", "2016-07-10 19:16:36", "2016-07-11 06:56:26", "2016-07-11 21:12:36", "2016-07-12 08:14:42", "2016-07-12 12:38:22", "2016-07-12 15:19:34", "2016-07-12 15:32:19", "2016-07-13 11:06:56", "2016-07-13 11:33:12", "2016-07-13 18:50:31", "2016-07-14 03:23:56", "2016-07-14 03:34:01", "2016-07-14 16:39:58", "2016-07-14 17:05:26", "2016-07-15 09:13:44", "2016-07-15 14:31:45", "2016-07-16 05:35:44", "2016-07-16 07:44:08", "2016-07-16 18:08:54", "2016-07-16 20:11:59", "2016-07-16 23:16:17", "2016-07-17 18:57:03", "2016-07-18 02:34:25", "2016-07-18 03:48:50", "2016-07-18 17:43:03", "2016-07-19 03:37:33", "2016-07-19 08:27:18", "2016-07-19 15:35:09", "2016-07-20 15:00:56", "2016-07-20 18:30:04", "2016-07-20 19:48:53", "2016-07-21 05:39:09", "2016-07-21 14:59:20", "2016-07-22 06:29:20", "2016-07-22 11:25:04", "2016-07-22 22:42:36", "2016-07-22 23:01:25", "2016-07-23 02:29:13", "2016-07-23 04:37:21", "2016-07-23 14:05:27", "2016-07-23 17:52:13", "2016-07-23 19:00:03", "2016-07-23 19:30:58", "2016-07-24 02:54:24", "2016-07-25 01:35:52", "2016-07-25 11:46:40", "2016-07-25 18:17:26", "2016-07-25 19:29:21", "2016-07-26 17:46:24", "2016-07-27 17:37:06", "2016-07-27 18:02:11", "2016-07-28 06:40:55", "2016-07-29 00:27:55", "2016-07-29 03:18:14", "2016-07-29 06:23:57", "2016-07-30 00:50:09", "2016-07-30 05:14:28", "2016-07-30 23:59:44", "2016-07-31 10:27:11", "2016-07-31 21:09:32", "2016-07-31 23:21:59", "2016-08-01 17:50:50", "2016-08-02 12:52:30", "2016-08-02 13:10:15", "2016-08-02 15:12:45", "2016-08-02 19:48:07", "2016-08-03 09:41:37", "2016-08-04 01:41:10", "2016-08-04 10:10:52", "2016-08-05 00:03:33", "2016-08-05 06:34:14", "2016-08-06 03:40:49", "2016-08-06 10:26:07", "2016-08-07 02:34:50", "2016-08-07 08:22:36", "2016-08-08 02:33:53", "2016-08-08 10:07:57", "2016-08-09 04:01:38", "2016-08-09 10:08:52", "2016-08-10 03:25:38", "2016-08-10 19:50:27", "2016-08-11 03:18:36", "2016-08-11 13:04:34", "2016-08-11 16:04:44", "2016-08-11 22:27:29", "2016-08-12 07:31:14", "2016-08-12 08:00:20", "2016-08-12 18:49:06", "2016-08-12 22:36:12", "2016-08-13 14:09:06", "2016-08-14 06:43:35", "2016-08-14 19:10:25", "2016-08-15 12:12:56", "2016-08-16 02:24:55", "2016-08-16 22:03:02", "2016-08-17 13:13:53", "2016-08-17 19:41:18", "2016-08-18 00:40:10", "2016-08-18 17:12:37", "2016-08-18 20:35:31", "2016-08-18 23:40:04", "2016-08-19 18:55:09", "2016-08-20 11:38:16", "2016-08-21 01:35:57", "2016-08-21 11:03:09", "2016-08-22 10:59:25", "2016-08-23 04:21:34", "2016-08-23 10:26:56", "2016-08-24 03:51:22", "2016-08-24 04:36:42", "2016-08-24 23:36:52", "2016-08-25 10:02:00", "2016-08-25 11:30:49", "2016-08-25 21:29:01", "2016-08-26 21:19:00", "2016-08-26 23:36:35", "2016-08-27 14:44:52", "2016-08-28 00:10:27", "2016-08-28 14:27:58", "2016-08-29 03:06:43", "2016-08-29 13:59:41", "2016-08-30 09:34:49", "2016-08-30 09:43:32", "2016-08-31 08:52:14", "2016-08-31 08:53:29", "2016-08-31 22:54:08", "2016-09-01 14:15:27", "2016-09-02 05:24:54", "2016-09-02 23:42:10", "2016-09-03 14:45:31", "2016-09-03 20:17:07", "2016-09-03 20:54:56", "2016-09-04 16:49:57", "2016-09-05 08:40:08", "2016-09-06 01:50:57", "2016-09-06 15:01:25", "2016-09-07 09:31:05", "2016-09-08 00:31:35", "2016-09-08 03:26:56", "2016-09-08 09:30:13", "2016-09-08 12:38:47", "2016-09-09 01:11:24", "2016-09-09 03:17:23", "2016-09-10 01:47:11", "2016-09-10 14:44:54", "2016-09-11 02:46:23", "2016-09-11 09:57:37", "2016-09-12 08:44:59", "2016-09-12 16:28:45", "2016-09-13 08:33:42", "2016-09-13 20:11:36", "2016-09-13 21:00:38", "2016-09-14 20:43:28", "2016-09-15 20:13:28", "2016-09-16 10:36:25", "2016-09-17 02:51:54", "2016-09-17 20:04:03", "2016-09-18 16:51:03", "2016-09-18 16:58:06", "2016-09-18 20:53:37", "2016-09-19 19:25:12", "2016-09-20 12:32:25", "2016-09-20 20:06:45", "2016-09-21 08:11:49", "2016-09-22 07:03:03", "2016-09-23 02:41:28", "2016-09-23 05:38:30", "2016-09-23 05:43:38", "2016-09-23 11:15:56", "2016-09-23 11:20:56", "2016-09-24 10:48:13", "2016-09-25 03:21:46", "2016-09-25 07:08:49", "2016-09-26 00:36:17", "2016-09-26 18:54:29", "2016-09-27 14:36:02", "2016-09-28 00:06:10", "2016-09-28 10:35:33", "2016-09-29 08:53:29", "2016-09-29 22:01:12", "2016-09-30 14:48:15", "2016-09-30 19:47:14", "2016-10-01 10:36:54", "2016-10-02 06:14:26", "2016-10-03 00:29:05", "2016-10-03 13:46:48", "2016-10-03 19:43:31", "2016-10-04 06:08:13", "2016-10-04 07:11:14", "2016-10-05 07:07:44", "2016-10-06 01:24:23", "2016-10-07 00:22:10", "2016-10-07 03:02:53", "2016-10-07 20:21:04", "2016-10-08 17:12:23", "2016-10-09 06:48:26", "2016-10-09 13:14:38", "2016-10-09 21:20:09", "2016-10-10 17:03:05", "2016-10-11 08:46:46", "2016-10-11 19:37:08", "2016-10-12 18:58:03", "2016-10-12 21:03:02", "2016-10-13 18:05:48", "2016-10-14 14:26:28", "2016-10-14 17:23:04", "2016-10-14 18:53:59", "2016-10-15 02:28:14", "2016-10-15 20:05:25", "2016-10-16 11:14:10", "2016-10-16 19:03:20", "2016-10-16 21:36:51", "2016-10-17 10:20:44", "2016-10-18 03:24:10", "2016-10-18 17:42:46", "2016-10-19 01:13:36", "2016-10-19 02:28:58", "2016-10-19 13:35:36", "2016-10-20 09:59:55", "2016-10-20 13:17:50", "2016-10-20 23:06:04", "2016-10-21 16:17:49", "2016-10-21 19:01:01", "2016-10-21 19:23:32", "2016-10-21 23:40:04", "2016-10-22 22:39:58", "2016-10-23 01:05:55", "2016-10-23 11:16:57", "2016-10-24 06:55:40", "2016-10-25 01:53:59", "2016-10-25 09:33:10", "2016-10-25 17:50:15", "2016-10-26 09:26:57", "2016-10-26 17:01:35", "2016-10-26 21:50:57", "2016-10-27 07:55:52", "2016-10-27 08:58:50", "2016-10-27 10:10:21", "2016-10-28 08:27:46", "2016-10-29 00:45:28", "2016-10-29 07:16:53", "2016-10-29 10:36:47", "2016-10-29 22:56:29", "2016-10-30 05:35:56", "2016-10-30 14:21:55", "2016-10-31 04:32:03", "2016-10-31 23:15:21", "2016-11-01 13:32:30", "2016-11-02 06:54:49", "2016-11-02 17:41:57", "2016-11-03 15:28:25", "2016-11-04 10:11:53", "2016-11-05 09:53:32", "2016-11-05 17:00:24", "2016-11-05 20:07:00", "2016-11-06 15:29:16", "2016-11-07 05:22:17", "2016-11-07 11:43:49", "2016-11-08 05:50:01", "2016-11-08 08:22:31", "2016-11-08 19:49:13", "2016-11-09 15:54:58", "2016-11-10 09:48:27", "2016-11-10 20:40:19", "2016-11-10 22:54:37", "2016-11-11 16:06:36", "2016-11-12 13:15:43", "2016-11-13 12:23:00", "2016-11-14 07:36:06", "2016-11-15 00:20:35", "2016-11-15 15:21:25", "2016-11-16 12:31:42", "2016-11-17 00:13:56", "2016-11-17 14:30:05", "2016-11-17 15:32:35", "2016-11-17 18:07:56", "2016-11-18 17:41:56", "2016-11-19 13:33:17", "2016-11-19 21:55:57", "2016-11-20 17:22:38", "2016-11-20 20:04:47", "2016-11-21 03:15:47", "2016-11-21 08:10:39", "2016-11-21 20:11:55", "2016-11-22 19:49:00", "2016-11-23 00:32:14", "2016-11-23 02:14:21", "2016-11-23 18:51:02", "2016-11-24 06:15:09", "2016-11-24 09:25:46", "2016-11-24 20:35:08", "2016-11-25 10:11:46", "2016-11-26 06:07:54", "2016-11-27 01:08:28", "2016-11-27 05:43:40", "2016-11-28 05:42:05", "2016-11-29 01:07:59", "2016-11-29 23:54:26", "2016-11-30 11:36:34", "2016-12-01 04:26:19", "2016-12-01 22:18:27", "2016-12-02 05:30:14", "2016-12-02 16:13:26", "2016-12-03 15:07:37", "2016-12-04 10:16:52", "2016-12-05 00:25:17", "2016-12-05 12:17:24", "2016-12-06 05:23:19", "2016-12-06 14:30:44", "2016-12-07 08:32:21", "2016-12-07 12:26:19", "2016-12-08 08:40:18", "2016-12-08 10:36:24", "2016-12-09 07:38:38", "2016-12-09 17:13:54", "2016-12-10 08:15:04", "2016-12-10 23:18:07", "2016-12-11 08:02:41", "2016-12-12 05:19:50", "2016-12-12 23:42:29", "2016-12-13 15:58:35", "2016-12-14 00:01:10", "2016-12-14 05:25:08", "2016-12-14 17:29:42", "2016-12-15 13:00:56", "2016-12-16 09:09:39", "2016-12-16 22:18:33", "2016-12-17 05:21:42", "2016-12-18 02:13:54", "2016-12-18 11:20:30", "2016-12-18 22:13:44", "2016-12-19 14:23:40", "2016-12-20 08:38:45", "2016-12-20 11:30:56", "2016-12-20 20:29:37", "2016-12-21 00:07:07", "2016-12-21 18:19:42", "2016-12-22 11:26:15", "2016-12-22 17:29:12", "2016-12-22 20:48:21", "2016-12-23 15:00:50", "2016-12-23 19:44:52", "2016-12-24 06:28:58", "2016-12-24 19:03:29", "2016-12-25 01:18:55", "2016-12-25 02:27:33", "2016-12-25 18:05:44", "2016-12-26 17:20:40", "2016-12-27 10:56:26", "2016-12-28 06:07:01", "2016-12-28 16:29:06", "2016-12-29 08:25:47", "2016-12-29 10:14:44", "2016-12-30 05:20:00", "2016-12-30 06:23:54", "2016-12-30 15:00:39", "2016-12-31 09:42:10", "2017-01-01 00:58:04", "2017-01-01 14:15:11", "2017-01-01 18:08:08", "2017-01-01 23:15:54", "2017-01-02 10:02:35", "2017-01-03 04:34:10", "2017-01-03 18:02:49", "2017-01-04 04:14:17", "2017-01-04 14:03:41", "2017-01-04 21:23:01", "2017-01-05 08:55:13", "2017-01-06 08:08:13", "2017-01-06 11:29:58", "2017-01-07 07:42:21", "2017-01-07 14:43:24", "2017-01-08 14:03:09", "2017-01-08 21:01:13", "2017-01-09 09:32:11", "2017-01-09 12:29:40", "2017-01-10 02:39:22", "2017-01-10 05:53:04", "2017-01-11 05:40:15", "2017-01-12 02:37:29", "2017-01-12 23:56:31", "2017-01-13 23:28:30", "2017-01-13 23:42:43", "2017-01-14 16:35:31", "2017-01-15 02:42:52", "2017-01-15 16:56:52", "2017-01-15 18:56:47", "2017-01-16 14:39:07", "2017-01-16 21:28:27", "2017-01-17 15:17:53", "2017-01-17 19:00:59", "2017-01-18 14:09:46", "2017-01-18 19:13:24", "2017-01-19 13:24:31", "2017-01-19 17:20:42", "2017-01-20 01:13:25", "2017-01-20 21:02:28", "2017-01-21 07:39:21", "2017-01-21 10:29:29", "2017-01-22 09:59:02", "2017-01-23 02:24:21", "2017-01-23 18:33:34", "2017-01-24 14:58:56", "2017-01-25 07:59:45", "2017-01-25 11:10:46", "2017-01-26 00:11:47", "2017-01-26 07:04:09", "2017-01-27 06:53:23", "2017-01-28 05:17:25", "2017-01-28 16:51:34", "2017-01-28 18:38:39", "2017-01-29 06:25:53", "2017-01-29 06:52:43", "2017-01-30 03:09:32", "2017-01-30 14:34:30", "2017-01-31 14:00:07", "2017-01-31 16:48:12", "2017-02-01 04:53:05", "2017-02-02 04:48:13", "2017-02-02 08:36:05", "2017-02-03 03:54:48", "2017-02-03 06:38:17", "2017-02-04 00:00:06", "2017-02-04 12:08:48", "2017-02-04 13:21:23", "2017-02-05 05:41:25", "2017-02-05 06:55:28", "2017-02-05 13:41:19", "2017-02-05 21:59:48", "2017-02-06 08:37:08", "2017-02-07 03:05:10", "2017-02-07 18:01:02", "2017-02-08 11:41:20", "2017-02-09 11:33:43", "2017-02-10 05:49:44", "2017-02-11 01:51:18", "2017-02-11 20:11:02", "2017-02-12 19:17:59", "2017-02-13 12:59:24", "2017-02-14 02:59:00", "2017-02-15 01:26:35", "2017-02-15 03:47:21", "2017-02-15 09:32:32", "2017-02-16 01:49:55", "2017-02-16 23:38:30", "2017-02-16 23:53:57", "2017-02-17 22:08:57", "2017-02-18 07:42:56", "2017-02-19 07:25:13", "2017-02-19 21:48:01", "2017-02-20 07:35:52", "2017-02-21 04:12:31", "2017-02-21 07:05:56", "2017-02-22 00:42:32", "2017-02-22 01:44:10", "2017-02-23 01:28:00", "2017-02-23 21:01:22", "2017-02-24 03:10:16", "2017-02-25 02:30:33", "2017-02-25 10:13:20", "2017-02-25 20:12:27", "2017-02-25 21:15:53", "2017-02-26 06:31:48", "2017-02-26 18:59:10", "2017-02-27 01:24:25", "2017-02-27 08:11:34", "2017-02-27 16:02:45", "2017-02-28 08:58:50", "2017-02-28 15:30:37", "2017-03-01 01:21:57", "2017-03-01 20:00:16", "2017-03-02 05:06:28", "2017-03-02 22:38:15", "2017-03-03 15:54:13", "2017-03-04 08:03:19", "2017-03-05 06:18:49", "2017-03-05 09:15:19", "2017-03-05 10:29:16", "2017-03-05 11:06:38", "2017-03-05 21:48:26", "2017-03-06 00:13:56", "2017-03-06 20:16:35", "2017-03-07 08:17:34", "2017-03-07 11:41:51", "2017-03-07 16:09:44", "2017-03-07 16:25:46", "2017-03-08 15:48:36", "2017-03-09 09:07:20", "2017-03-10 00:19:15", "2017-03-10 23:36:26", "2017-03-11 02:58:59", "2017-03-11 03:18:49", "2017-03-11 10:23:29", "2017-03-12 05:52:06", "2017-03-12 23:28:14", "2017-03-13 08:49:35", "2017-03-13 17:59:18", "2017-03-14 08:56:16", "2017-03-15 01:13:54", "2017-03-15 14:22:42", "2017-03-15 15:21:28"};

	srand(time(NULL));
	if (n <= 0 || n > 1000){
		n = rand() % 1000 + 1; //generating int between 1 and 1.000
	}
	players = malloc(sizeof(struct s_player *) * (n + 1));
	for (int i = 0; i < n; i++)
	{
		players[i] = createRandomPlayer(names[rand() % 100], timeStamps[i]);
	}
	players[n] = NULL;
	return (players);
}

struct s_player *createRandomPlayer(char *name, char *timeStamp){
	int scores[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	struct s_player *player = malloc(sizeof(struct s_player));
	if (player){
		player->name = strdup(name);
		usleep(2);
		player->score = scores[rand() % 10] * 10;
		player->timeStamp = strdup(timeStamp);
	}
	return (player);
}
