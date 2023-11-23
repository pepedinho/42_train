#include <stdio.h>
#include <stdlib.h>

#define EPSILON 0.1
#define ALPHA 0.1
#define GAMMA 0.9
#define ROWS 6
#define COLS 7

typedef struct
{
    int row;
    int col;
} StateAction;

typedef struct
{
    int plateau[ROWS][COLS];
    char player;
} GameState;



// Fonction pour afficher le plateau
void afficherPlateau(int plateau[ROWS][COLS]) {
    // Afficher les indices de colonnes
    system("clear");
    for (int i = 0; i < COLS; ++i) {
        printf("%d ", i + 1);
    }
    printf("\n");

    // Afficher le plateau
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", plateau[i][j] == 0 ? '-' : (plateau[i][j] == 1 ? 'X' : 'O'));
        }
        printf("\n");
    }
}

int check_win(int plateau[ROWS][COLS])
{
    // Vérification des alignements horizontaux
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (plateau[i][j] != 0 &&
                plateau[i][j] == plateau[i][j + 1] &&
                plateau[i][j] == plateau[i][j + 2] &&
                plateau[i][j] == plateau[i][j + 3]) {
                return plateau[i][j];  // Le joueur actuel a gagné
            }
        }
    }

    // Vérification des alignements verticaux
    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (plateau[i][j] != 0 &&
                plateau[i][j] == plateau[i + 1][j] &&
                plateau[i][j] == plateau[i + 2][j] &&
                plateau[i][j] == plateau[i + 3][j]) {
                return plateau[i][j];  // Le joueur actuel a gagné
            }
        }
    }

    // Vérification des alignements diagonaux (de gauche à droite)
    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (plateau[i][j] != 0 &&
                plateau[i][j] == plateau[i + 1][j + 1] &&
                plateau[i][j] == plateau[i + 2][j + 2] &&
                plateau[i][j] == plateau[i + 3][j + 3]) {
                return plateau[i][j];  // Le joueur actuel a gagné
            }
        }
    }

    // Vérification des alignements diagonaux (de droite à gauche)
    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 3; j < COLS; ++j) {
            if (plateau[i][j] != 0 &&
                plateau[i][j] == plateau[i + 1][j - 1] &&
                plateau[i][j] == plateau[i + 2][j - 2] &&
                plateau[i][j] == plateau[i + 3][j - 3]) {
                return plateau[i][j];  // Le joueur actuel a gagné
            }
        }
    }

    return 0;  // Aucun joueur n'a encore gagné
    
}

int put_a_token(int plateau[ROWS][COLS], int col, char player)
{
    int i = ROWS - 1;

    while (i >= 0 && plateau[i][col - 1] != 0)
    {
        i--;
    }

    if (i >= 0)
    {
        plateau[i][col -  1] = player == 'X' ? 1 : 2;
    }
    else
    {
        printf("colonne pleine!\n");
    }
    return 1;
}


int choose_move(int qTable[ROWS][COLS], int row, double epsilon)
{
    if ((double)rand() / RAND_MAX < epsilon) 
    {
        //choisire l'action au hasard
        return rand() % COLS;
    }
    else
    {
        //chercher la meilleur action pour l'etat actuel dans la qTable
        int best_move = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (qTable[row][j] < qTable[row][best_move])
            {
                best_move = j;
            }
        }
        return best_move;
    }
}

void update_game_state(GameState *state, int col)
{
    put_a_token(state->plateau, col, state->player);

    state->player = (state->player == 'X') ? 'O' : 'X';
}


void sarsa(int qTable[ROWS][COLS])
{

    GameState state;

    printf("Choisissez un signe 'X' ou 'O' : ");
    scanf("%c", &state.player);
    printf("\n");

    StateAction action_state, new_action_state;
    int action, new_action;
    double reward;

    action_state.row = 0;
    action_state.col = choose_move(qTable, action_state.row, EPSILON);
    action = action_state.row;

    int run = 1;
    int episode = 100, j = 0;
    
    while (j < episode)
    {
        state.player = 'X';
        action_state.row = 0;
        action_state.col = choose_move(qTable, action_state.row, EPSILON);
        action = action_state.col;

        while (run)
        {
            // Afficher le plateau initial
            afficherPlateau(state.plateau);

            StateAction before_action = action_state;

            update_game_state(&state, action);

            afficherPlateau(state.plateau);

            if (check_win(state.plateau) != 0)
            {   
                qTable[before_action.row][before_action.col] += ALPHA * (reward - qTable[before_action.row][before_action.col]);
                reward = 1.0;
                run = 0;
                break;
            }

            // Choix de la prochaine action
            new_action_state.row = 0; // Vous pouvez ajuster cela selon vos besoins
            new_action_state.col = choose_move(qTable, new_action_state.row, EPSILON);
            new_action = new_action_state.col;

            // Mettre à jour la Q-table
            qTable[before_action.row][before_action.col] += ALPHA * (qTable[action_state.row][new_action] - qTable[before_action.row][before_action.col]);

            // Mettre à jour l'action courante et continuer la boucle
            action_state = new_action_state;
            action = new_action;
        }
        run = 1;
        printf("episode : %d", j);
        j++;
    }
    
}

int main() {

    // char player = '\0';
    // int moove = 0;

    // // Initialiser le plateau avec des zéros (pas de jeton)
    // int plateau[ROWS][COLS] = {0};

    // int run = 1;
    // printf("Choisissez un signe 'X' ou 'O' : ");
    // scanf("%c", &player);
    // printf("\n");

    // while (run)
    // {

    //     Afficher le plateau initial
    //     afficherPlateau(plateau);

    //     printf("entrée une collone : ");
    //     scanf("%d", &moove);

    //     put_a_token(plateau, moove, player);

    //     afficherPlateau(plateau);
    //     if (check_win(plateau) != 0)
    //     {
    //         break;
    //     }
    //     player = player == 'X' ? 'O' : 'X';

    // }
    int qTable[ROWS][COLS] = {0};
    sarsa(qTable);

    return 0;
}
