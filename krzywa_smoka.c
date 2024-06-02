//Poniżej następuje zastosowanie wszystkich potrzebnych
//w moim programie plików nagłówkowych, które odpowiadają
//chociażby za rysowanie graficznego wyniku działania
//programu, zastosowania typu zmiennej "bool", która nie
//jest nominalnie zawarta w pliku nagłówkowym "stdio.h"
//czy też za pracę na plikach.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "turtle.h"

//Poniżej zdefiniowany został za pomocą słowa kluczowego
//"typedef" nowy typ zmiennej "struct Node" z etykietą
//"Node_t", która przechowuje zmienną "step", która definiuje
//kolejny krok oraz strukturę "Node *pNode", która przechowuje
//adres struktury.

typedef struct Node
{
    char step;
    struct Node *pNode;
} Node_t;

//Poniżej następuje definicja funkcji "init_node", która
//służy do (jak sama nazwa wskazuje) inicjonowania określonego
//"node'a", a dokładniej jego adresu i kroku i następnie zwraca
//owego "node'a". Za argument funkcja ta przyjmuje "step" do
//swojego działania.

Node_t* init_node(char step)
{
    Node_t *node = malloc(sizeof(Node_t));
    node->step = step;
    node->pNode = NULL;
    return node;
}

//Poniżej w kodzie następuje deklaracja wszystkich funkcji tego
//programu, które służą odpowiednio do: budowania całej "listy",
//wypisywania jej do konsoli oraz do pliku tekstowego
//"output_text.txt", rysowania graficznego rezultatu działania
//programu oraz czytania pliku tekxtowego "config.txt", z którego
//pobierane są dane początkowe programu. Dodatkowo zadeklarowanie
//typu zmiennych, jakie dana funkcja potrzebuje do prawidłowego
//działania.

void build_list(Node_t *, int);
void print_list(Node_t *, FILE *);
void draw_list(Node_t *, int, int, int);
void read_config(FILE*, int*, int*, int*, int*);

int main()
{
//Definicja wszystkich zmiennych w funkcji "main" typu "int".

    int iter, width, height, step, decision;

//Otwarcie dwóch plików, pierwszy to "config" programu, a
//drugi to plik zawierający tekstową reprezentację działania
//algorytmu oraz sprawdzenie, czy nie występuje żaden błąd,
//jak np. brak pliku "config"w tej samej lokalizacji, co plik
//programu.

    FILE *file = fopen("config.txt", "r");
    FILE *result = fopen("output_text.txt", "w");

    if (!file)
    {
        printf("Error\n");
        return 1;
    }

    if (!result)
    {
        printf("Error\n");
        return 1;
    }

//Poniżej zdefiniowanie dwa pierwsze "node'y", które muszą
//być zdefiniowane wcześniej, żeby funkcja "build_list"
//działała poprawnie.

    Node_t *rootNode = init_node('F');
    Node_t *xNode = init_node('X');
    rootNode->pNode = xNode;

//Wywołanie do działania funkcji "read_config", "build_list"
//oraz "print_list" z odpowiednimi argumentami, do prawidłowego
//działania każdej funkcji.

    read_config(file, &iter, &width, &height, &step);
    build_list(rootNode, iter);
    print_list(rootNode, result);

//Poniżej występuje część kodu, odpowiadająca za decyzję użytkownika,
//która przyjmując odpowiednią wartość dla zmiennej "decision"
//albo uruchamia funckję "draw_list" do graficznego efektu działania
//programu albo nie.

    printf("\nChcesz graficzna reprezentacje krzywej? '1' - tak, '0' lub inna liczba niz '1' - nie:");
    scanf("%d", &decision);

    if(decision == 1)
    {
        draw_list(rootNode, width, height, step);
    }
    
//Zamknięcie obu plików, z których wczytywaliśmy i do których
//zapisywaliśmy dane.

    fclose(file);
    fclose(result);

    return 0;
}

//Poniżej została zadeklarowana funkcja "build_list", która
//jest główną funkcją całego algorytmu. Do działania funkcji
//potrzebne są dane zmiennej "int iter" oraz "Node_t *firstNode".
//Na początku funkcja ta sprawdza, czy "iter" jest mniejszy
//bądź równy zero. Jeżeli tak, to funkcja nie zwraca niczego
//tak naprawdę, a jeżeli "iter" jest większy niż 0, to
//rozpoczyna się algorytm w pętli "while", dopóki zmienna
//"current" nie jest wartością NULL. Jeżeli nie jest, to
//wykonuje się symulacja na takiej zasadzie: X -> X+YF,
//Y -> FX-Y, a początkowy string to: FX, gdzie:
//'X', 'Y' - Zmienne pomocnicze
//'F' - ruch do przodu
//'+' - obrót w lewo o określony kąt
//'-' - obrót w prawo o określony kąt
//Po wyjściu z pętli "while", funkcja wywołuje samą siebie
//tym razem z "iter - 1"

void build_list(Node_t *firstNode, int iter)
{
    if (iter <= 0) return;

    Node_t *current = firstNode;
    while (current != NULL)
    {
        if (current->step == 'X')
        {
            Node_t *nodeX = init_node('X');
            Node_t *nodePlus1 = init_node('+');
            Node_t *nodeY = init_node('Y');
            Node_t *nodeF = init_node('F');
            Node_t *nodePlus2 = init_node('+');

            nodeX->pNode = nodePlus1;
            nodePlus1->pNode = nodeY;
            nodeY->pNode = nodeF;
            nodeF->pNode = nodePlus2;
            nodePlus2->pNode = current->pNode;

            current->step = nodeX->step;
            current->pNode = nodeX->pNode;

            free(nodeX);
            current = nodePlus2->pNode;
        } 
        
        else if (current->step == 'Y')
        {
            // Y -> -FX-Y
            Node_t *nodeMinus = init_node('-');
            Node_t *nodeF = init_node('F');
            Node_t *nodeX = init_node('X');
            Node_t *nodeMinus2 = init_node('-');
            Node_t *nodeY = init_node('Y');

            nodeMinus->pNode = nodeF;
            nodeF->pNode = nodeX;
            nodeX->pNode = nodeMinus2;
            nodeMinus2->pNode = nodeY;
            nodeY->pNode = current->pNode;

            current->step = nodeMinus->step;
            current->pNode = nodeMinus->pNode;

            free(nodeMinus);
            current = nodeY->pNode;
        } 
        
        else
        {
            current = current->pNode;
        }
    }

    build_list(firstNode, iter - 1);
}

//Poniższa funkcja "print_list" sprawia, że cały algorytm
//wypisuje się jednocześnie zarówno do konsoli, jak i do
//pliku tekstowego "output_text.txt". Funkcja za argumenty
//przyjmuje "Node_t *nextNode" oraz "FILE *result".

void print_list(Node_t *nextNode, FILE *result)
{

    if (nextNode != NULL)
    {
        printf("%c", nextNode->step);
        fprintf(result, "%c", nextNode->step);
        print_list(nextNode->pNode, result);
    }

}

//Poniższa funkcja "read_config" wyczytuje z pliku "config.txt"
//(o ile takowy istnieje!) dane do stworzenia algorytmu.
//Do działania funkcja za argumenty przyjmuje "FILE *file",
//"int *iter", "int *width", "int *height" oraz "int *step".

void read_config(FILE *file, int *iter, int *width, int *height, int *step)
{
    fscanf(file, "iter=%d\n", iter);
    fscanf(file, "width=%d\n", width);
    fscanf(file, "height=%d\n", height);
    fscanf(file, "step=%d\n", step);
}

//Poniższa funkcja "draw_list" odpowiada za rysowanie graficznej
//interpretacji "krzywej smoka" (o ile użytkownik chciał!). Ta
//funkcja do działania za argumenty przyjmuje: "Node_t *nextNode",
//"int width", "int height" oraz "int step". Jeżeli użytkownik
//zechciał takowej reprezentacji, to funkcja zaczyna wypisywać
//najpierw wartości zawartych w pliku "config.txt" danych.
//Następnie przechodzimy do pętli "while", gdzie dopóki
//"nextNode" nie ma wartości NULL, to wypisuje każdy "step",
//czyli krok w programie, a potem rysuje za pomocą działań
//zawartych w pliku nagłówkowych "turtle.h" rysuje odpowiednie
//wzory, w zależności od tego, na jaki "step" aktualnie wskazuje
//program.

void draw_list(Node_t *nextNode, int width, int height, int step)
{
    printf("Width: %d, Height: %d, Step: %d\n", width, height, step);

    turtle_init(width, height);
    turtle_pen_up();
    turtle_goto_real(0, 0);
    turtle_pen_down();

    while (nextNode != NULL)
    {
        printf("Next Node Step: %c\n", nextNode->step);

        if (nextNode->step == 'F')
        {
            turtle_forward(step);
        }
        else if (nextNode->step == '+')
        {
            turtle_turn_left(90);
        }
        else if (nextNode->step == '-')
        {
            turtle_turn_right(90);
        }
        nextNode = nextNode->pNode;
    }

    turtle_draw_turtle();
    turtle_save_bmp("output.bmp");
    turtle_cleanup();
}