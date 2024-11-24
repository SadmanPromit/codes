/// v10; build statically: gcc tictactoe.c -o tictactoe -static -lpthread
#include <stdio.h>
#include <stdlib.h> //Has system("cls") for Clear Screen
#include <windows.h>    // Has Beep() for playing sound based on custom music frequencies
#include <conio.h>  // Has _getch() to take single character input without echoing
#include <pthread.h>    // Has pthread_t & pthread_create() for Multi-Threading to play sound in the background
#define STRING_SIZE 100
#define USER_NUMBER 1
#define KEY "@&^^*"
#define NOTE_A  880
#define NOTE_B  988
#define NOTE_C  523
#define NOTE_D  587
#define NOTE_E  659
#define NOTE_F  698
#define NOTE_G  784
#define NOTE_CH 1047
typedef struct {
    int board[9],
        mode,
        sound,
        autosave,
        player,
        advanced_game_won,
        normal_game_won,
        advanced_game_won_streak,
        normal_game_won_streak,
        highest_advanced_game_won_streak,
        highest_normal_game_won_streak,
        advanced_game_draw,
        normal_game_draw,
        advanced_game_lost,
        normal_game_lost;
    char name[STRING_SIZE], password[STRING_SIZE];
} User;
void *gameWinSound() {  // Mozart Inspired sound track
    Beep(NOTE_D, 300);
    Sleep(50);
    Beep(NOTE_F, 300);
    Sleep(50);
    Beep(NOTE_A, 300);
    Sleep(50);
    Beep(NOTE_D, 200);
    Sleep(150);
    Beep(NOTE_CH, 400);
    Sleep(200);
    Beep(NOTE_A, 200);
    Sleep(50);
    Beep(NOTE_F, 300);
    Sleep(150);
    Beep(NOTE_D, 500);
}
int maxNum(int a, int b) {
    return (a > b) ? a : b;
}
int minNum(int a, int b) {
    return (a < b) ? a : b;
}
char gridCharX(int i) { // For user X
    switch(i) {
        case -1: return 'X';
        case 0: return ' ';
        case 1: return 'O';
        default: return ' ';
    }
}
char gridCharO(int i) { // For user O
    switch(i) {
        case -1: return 'O';
        case 0: return ' ';
        case 1: return 'X';
        default: return ' ';
    }
}
void draw(int b[9], int player) {
    if(player == -1)
        printf(" %c | %c | %c\n---+---+---\n %c | %c | %c\n---+---+---\n %c | %c | %c\n",
            gridCharX(b[0]), gridCharX(b[1]), gridCharX(b[2]),
            gridCharX(b[3]), gridCharX(b[4]), gridCharX(b[5]),
            gridCharX(b[6]), gridCharX(b[7]), gridCharX(b[8]));
    else if(player == 1)
        printf(" %c | %c | %c\n---+---+---\n %c | %c | %c\n---+---+---\n %c | %c | %c\n",
            gridCharO(b[0]), gridCharO(b[1]), gridCharO(b[2]),
            gridCharO(b[3]), gridCharO(b[4]), gridCharO(b[5]),
            gridCharO(b[6]), gridCharO(b[7]), gridCharO(b[8]));
}
int win(const int board[9]) {
    unsigned wins[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    int i;
    for(i = 0; i < 8; ++i)
        if(board[wins[i][0]] != 0 && board[wins[i][0]] == board[wins[i][1]] && board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    return 0;
}
int minimax(int board[9], int player) { // Minimax algorithm for Advanced Game Logic
    int winner = win(board);
    if(winner != 0) return winner * player;
    int move = -1, score = -2, i;
    for(i = 0; i < 9; ++i)
        if(board[i] == 0) {
            board[i] = player;
            int thisScore = -minimax(board, player * -1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }
            board[i] = 0;
        }
    if(move == -1) return 0;
    return score;
}
int minimax_pruned(int board[9], int player, int alpha, int beta) { // Minimax with Alpha-Beta pruning algorithm for Normal Game Logic
    int winner = win(board);
    if(winner != 0) return winner * player;
    int score = (player == 1) ? -2 : 2;
    for(int i = 0; i < 9; ++i)
        if(board[i] == 0) {
            board[i] = player;
            if(player == 1) {
                score = maxNum(score, -minimax_pruned(board, -1, alpha, beta));
                alpha = maxNum(alpha, score);
            } else {
                score = minNum(score, -minimax_pruned(board, 1, alpha, beta));
                beta = minNum(beta, score);
            }
            board[i] = 0;
            if(alpha >= beta) break;
        }
    if(score == -2 || score == 2) return 0;
    return score;
}
void computerMove(int board[9], int mode) {
    int move = -1, score = -2, alpha = -2, beta = 2;
    for(int i = 0; i < 9; ++i)
        if(board[i] == 0) {
            board[i] = 1;
            int tempScore;
            if(mode == 2)
                tempScore = -minimax(board, -1);
            else if(mode == 1)
                tempScore = -minimax_pruned(board, -1, alpha, beta);
            board[i] = 0;
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    board[move] = 1;
}
void playerMove(int board[9]) {
    int move = 0;
    do {
        move = _getch() - '1';  // For Base index 0
    } while(move < 0 || move >= 9 || board[move] != 0);
    board[move] = -1;
}
void *BeepPointer() {
    Beep(NOTE_G, 10);
}
void refreshSound(pthread_t sound_thread, User *user) {
    system("cls");
    if(user -> sound)
        pthread_create(&sound_thread, NULL, *BeepPointer, NULL);
}
void encryption(char *string) {
    size_t key_len = strlen(KEY);
    for(size_t i = 0; string[i] != '\0'; i++) {
        string[i] ^= KEY[i % key_len];
    }
}
int writeFile(User *user) {
    int write_flag = 0;
    FILE *db = fopen("db.bin", "wb");
    if(!db) {
        perror("Cannot save file.\n");
        return write_flag;
    }
    write_flag = fwrite(user, sizeof(User), USER_NUMBER, db);
    fclose(db);
    return write_flag;
}
int readFile(User *user) {
    int read_flag = 0;
    FILE *db = fopen("db.bin", "rb");
    if(!db)
        return read_flag;
    read_flag = fread(user, sizeof(User), USER_NUMBER, db);
    fclose(db);
    return read_flag;
}
void menu(pthread_t sound_thread, FILE *db, User *user, int guest, int *new_game_flag) {
    char menu_guest_string[STRING_SIZE];
    guest ? strcpy(menu_guest_string, "Create New Profile") : strcpy(menu_guest_string, "Save");
    printf(":::Tic-Tac-Toe:::\n[1] New Game\n[2] Profile Stats\n[3] Settings\n[4] %s\n[5] About\n[6] Exit\nSelect any from [1] to [6]: ", menu_guest_string);
    char menu = _getch();
    refreshSound(sound_thread, user);
    switch(menu) {
        case '1':
            *new_game_flag = 1;
            break;
        case '2':
            printf("%s's Game Stats:\nAdvanced game won: %d\nNormal game won: %d\nAdvanced game won streak: %d\nNormal game won streak: %d\nHighest advanced game won streak: %d\nHighest normal game won streak: %d\nAdvanced game draw: %d\nNormal game draw: %d\nAdvanced game lost: %d\nNormal game lost: %d\n",
                user -> name,
                user -> advanced_game_won,
                user -> normal_game_won,
                user -> advanced_game_won_streak,
                user -> normal_game_won_streak,
                user -> highest_advanced_game_won_streak,
                user -> highest_normal_game_won_streak,
                user -> advanced_game_draw,
                user -> normal_game_draw,
                user -> advanced_game_lost,
                user -> normal_game_lost);
            break;
        case '3': {
            int goback_flag = 0;
            char mode_string[STRING_SIZE], sound_string[STRING_SIZE], autosave_string[STRING_SIZE];
            (user -> mode == 2) ? strcpy(mode_string, "Advanced") : strcpy(mode_string, "Normal");
            (user -> sound == 1) ? strcpy(sound_string, "On") : strcpy(sound_string, "Off");
            (user -> autosave == 1) ? strcpy(autosave_string, "On") : strcpy(autosave_string, "Off");
            printf(":::Settings:::\n[1] Game Mode Setting: %s\n[2] Sounds Setting: %s\n[3] Auto Save Setting: %s\n[4] Name: %s\n[5] Password\n[6] Go Back\nSelect any from [1] to [6]: ",
                   mode_string, sound_string, autosave_string, user -> name);
            char sub_menu = _getch();
            refreshSound(sound_thread, user);
            switch(sub_menu) {
                case '1':
                    printf("Select [1] Normal or [2] Advanced Difficulty Mode: ");
                    do {
                        user -> mode = _getch() - '0';
                        refreshSound(sound_thread, user);
                        if(user -> mode == 1 || user -> mode == 2)
                            break;
                        printf("Invalid input. Please select [1] Normal or [2] Advanced: ");
                    } while(1);
                    break;
                case '2':
                    printf("Select Game Sound [1] On or [0] Off: ");
                    do {
                        user -> sound = _getch() - '0';
                        refreshSound(sound_thread, user);
                        if(user -> sound == 0 || user -> sound == 1)
                            break;
                        printf("Invalid input. Please select Game Sound [1] On or [0] Off: ");
                    } while(1);
                    break;
                case '3':
                    printf("Select Game Auto saving [1] On or [0] Off: ");
                    do {
                        user -> autosave = _getch() - '0';
                        refreshSound(sound_thread, user);
                        if(user -> autosave == 0 || user -> autosave == 1)
                            break;
                        printf("Invalid input. Please select Game Auto saving [1] On or [0] Off: ");
                    } while(1);
                    break;
                case '4':
                    printf("Enter Name: ");
                    fgets(user -> name, STRING_SIZE, stdin);
                    user -> name[strcspn(user -> name, "\n")] = '\0';
                    refreshSound(sound_thread, user);
                    break;
                case '5':
                    printf("Enter Password: ");
                    int i = 0;
                    for(; (user -> password[i] = _getch()) != '\r'; ++i)
                        printf("*");
                    encryption(user -> password);
                    user -> password[i] = '\0';
                    refreshSound(sound_thread, user);
                    break;
                case '6':
                    goback_flag = 1;
                    break;
                default:
                    printf("Invalid input.\n");
            }
            if(!goback_flag && writeFile(user))
                printf("Settings saved.\n");
            break;
        }
        case '4':
            if(guest) {
                printf("Enter Name: ");
                fgets(user -> name, STRING_SIZE, stdin);
                user -> name[strcspn(user -> name, "\n")] = '\0';
                refreshSound(sound_thread, user);
                printf("Enter Password: ");
                int i = 0;
                for(; (user -> password[i] = _getch()) != '\r'; ++i)
                    printf("*");
                encryption(user -> password);
                user -> password[i] = '\0';
                user -> autosave = 1;
                refreshSound(sound_thread, user);
                writeFile(user);
                printf("Account created.\n");
            }
            else {
                writeFile(user);
                refreshSound(sound_thread, user);
                printf("Saved.\n");
            }
            break;
        case '5':
            printf("Tic Tac Toe\n(c) 2024 Sadman Sakib Khan Promit\nhttps://www.spromits.com/\n");
            break;
        case '6':
            refreshSound(sound_thread, user);
            printf("Game Closed.\n");
            exit(0);
        default:
            printf("Invalid input.\n");
    }
}
int main() {
    pthread_t sound_thread;
    FILE *db;
    User *user = malloc(sizeof(User));
    int guest = 1;
    if(readFile(user)) {
        guest = 0;
        char buffer[STRING_SIZE];
        printf("Enter Password: ");
        int i = 0;
        for(; (buffer[i] = _getch()) != '\r'; ++i)
            printf("*");
        encryption(buffer);
        buffer[i] = '\0';
        if(strcmp(buffer, user -> password)) {
            guest = 1;
            refreshSound(sound_thread, user);
            printf("Wrong password. Saving will override any saved progress!\n");
        }
        else {
            refreshSound(sound_thread, user);
            printf("Game data loaded.\n");
        }
    }
    if(guest) {
        user -> mode = 2;
        user -> sound = 1;
        user -> autosave = 0;
        user -> player = -1;
        user -> advanced_game_won =
        user -> normal_game_won =
        user -> advanced_game_won_streak =
        user -> normal_game_won_streak =
        user -> highest_advanced_game_won_streak =
        user -> highest_normal_game_won_streak =
        user -> advanced_game_draw =
        user -> advanced_game_lost =
        user -> normal_game_draw =
        user -> normal_game_lost = 0;
        strcpy(user -> name, "Guest");
        strcpy(user -> password, "");
    }
    while(1) {
        int new_game_flag = 0;
        while(!new_game_flag)
            menu(sound_thread, db, user, guest, &new_game_flag);
        for(int i = 0; i < 9; ++i)
            user -> board[i] = 0;
        unsigned turn;
        for(turn = 0; turn < 9 && win(user -> board) == 0; ++turn)  // If turn is even and player chose X, or turn is odd and player chose O
            if(((turn % 2) == 0 && user -> player == -1) || ((turn % 2) == 1 && user -> player == 1)) {
                draw(user -> board, user -> player);
                char mode_string[STRING_SIZE], player_string[STRING_SIZE];
                (user -> mode == 2) ? strcpy(mode_string, "Advanced") : strcpy(mode_string, "Normal");
                (user -> player == -1) ? strcpy(player_string, "X") : strcpy(player_string, "O");
                printf("Game mode: %s and you are player: %s. Valid inputs: [1] to [9]: ",
                       mode_string, player_string);
                playerMove(user -> board);
                refreshSound(sound_thread, user);
            }
            else
                computerMove(user -> board, user -> mode);
        switch(win(user -> board)) {
            case 0:
                if(user -> mode == 2) {
                    ++user -> advanced_game_draw;
                    user -> advanced_game_won_streak = 0;
                }
                else {
                    ++user -> normal_game_draw;
                    user -> normal_game_won_streak = 0;
                }
                printf("It's a Draw!\n");
                break;
            case 1:
                draw(user -> board, user -> player);
                if(user -> mode == 2) {
                    ++user -> advanced_game_lost;
                    user -> advanced_game_won_streak = 0;
                }
                else {
                    ++user -> normal_game_lost;
                    user -> normal_game_won_streak = 0;
                }
                printf("You lose!\n");
                break;
            case -1:
                if(user -> mode == 2) {
                    ++user -> advanced_game_won;
                    ++user -> advanced_game_won_streak;
                }
                else {
                    ++user -> normal_game_won;
                    ++user -> normal_game_won_streak;
                }
                printf("You win!\n");
                if(user -> advanced_game_won_streak) {
                    user -> highest_advanced_game_won_streak =
                        maxNum(user -> highest_advanced_game_won_streak, user -> advanced_game_won_streak);
                    printf("Game Won Streak: %d\n", user -> advanced_game_won_streak);
                }
                else if(user -> normal_game_won_streak) {
                    user -> highest_normal_game_won_streak =
                        maxNum(user -> highest_normal_game_won_streak, user -> normal_game_won_streak);
                    printf("Game Won Streak: %d\n", user -> normal_game_won_streak);
                }
                if(user -> sound)
                    pthread_create(&sound_thread, NULL, gameWinSound, NULL);
        }
        user -> player *= -1;
        if(user -> autosave && writeFile(user))
            printf("Saved.\n");
    }
    pthread_join(sound_thread, NULL);
    return 0;
}