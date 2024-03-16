#include "interfaceGraphique.h"
#include "grapheNOrienteNV.h"
#include "grapheNOrienteV.h"
#include "grapheOrienteNV.h"
#include "grapheOrienteV.h"

interfaceGraphique::interfaceGraphique()

{

}
void interfaceGraphique::drawGraphNONV(vector<vector<int>> adjMatrix) const {
    int numNodes = adjMatrix.size() - 1; // On ignore la première ligne et la première colonne
    /* request autodetection */
    int gdriver = DETECT, gmode, errorcode;
    int xmax, ymax;

    /* initialize graphics and local variables */
    initgraph(&gdriver, &gmode, "");
    int nodeRadius = 25;
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    // Dessiner les nœuds
    for(int i = 1; i <= numNodes; i++) {
        int angle = (i-1) * 360 / numNodes;
        int x = centerX + 200 * cos(angle * M_PI / 180);
        int y = centerY + 200 * sin(angle * M_PI / 180);
        circle(x, y, nodeRadius);
        char nodeNum[10];
        sprintf(nodeNum, "%d", i);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(x - textwidth(nodeNum) / 2, y - textheight(nodeNum) / 2, nodeNum);
    }

    // Dessiner les arêtes
    for(int i = 1; i <= numNodes; i++) {
        for(int j = i + 1; j <= numNodes; j++) {
            if(adjMatrix[i][j] == 1) {
                int x1 = centerX + 200 * cos((i-1) * 360 / numNodes * M_PI / 180);
                int y1 = centerY + 200 * sin((i-1) * 360 / numNodes * M_PI / 180);
                int x2 = centerX + 200 * cos((j-1) * 360 / numNodes * M_PI / 180);
                int y2 = centerY + 200 * sin((j-1) * 360 / numNodes * M_PI / 180);
                line(x1, y1, x2, y2);
            }
        }
    }

    // Attendre un clic de souris pour fermer la fenêtre graphique
    while(!kbhit()) {
        delay(100);
    }
    closegraph();
}
void interfaceGraphique::drawGraphNOV(vector<vector<int>> adjMatrix) const {
    int numNodes = adjMatrix.size() - 1; // exclure la première ligne et la première colonne
    // request autodetection
    int gdriver = DETECT, gmode, errorcode;
    int xmax, ymax;

    // initialize graphics and local variables

    initgraph(&gdriver, &gmode, "");

    int nodeRadius = 25;
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    // Dessiner les nœuds
    for (int i = 0; i < numNodes; i++) {
        int angle = i * 360 / numNodes;
        int x = centerX + 200 * cos(angle * M_PI / 180);
        int y = centerY + 200 * sin(angle * M_PI / 180);
        setcolor(15);
        circle(x, y, nodeRadius);
        char nodeNum[10];
        sprintf(nodeNum, "%d", i + 1);
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(x - textwidth(nodeNum) / 2, y - textheight(nodeNum) / 2, nodeNum);
    }
    vector<int>couleur(16);
    for(int i=0;i<couleur.size();i++)
    {

        couleur[i] = i;

    }
    couleur[0]=12;
    couleur[1]=14;
        // Dessiner les arêtes
   // Dessiner les arêtes
// Dessiner les arêtes
for (int i = 0; i < numNodes; i++) {
    for (int j = i + 1; j < numNodes; j++) {
        if (adjMatrix[i + 1][j + 1] != -1 && i!=j) {
            int x1 = centerX + 200 * cos(i * 360 / numNodes * M_PI / 180);
            int y1 = centerY + 200 * sin(i * 360 / numNodes * M_PI / 180);
            int x2 = centerX + 200 * cos(j * 360 / numNodes * M_PI / 180);
            int y2 = centerY + 200 * sin(j * 360 / numNodes * M_PI / 180);
            setcolor(couleur[i]);
            line(x1, y1, x2, y2);
            char weight[10];
            sprintf(weight, "%d", adjMatrix[i + 1][j + 1]);
            settextstyle(3, HORIZ_DIR, 2);
            // on peut ajuster le 20 pour controler la distabce entre l'arête et le poid
            int weightX = (x1 + x2) / 2 + 20 * cos((i + j) * 360 / (2 * numNodes) * M_PI / 180);
            int weightY = (y1 + y2) / 2 + 20 * sin((i + j) * 360 / (2 * numNodes) * M_PI / 180);
            outtextxy(weightX - textwidth(weight) / 2, weightY - textheight(weight) / 2, weight);
        }
    }
}


    // Attendre un clic de souris pour fermer la fenêtre graphique
    while (!kbhit()) {
        delay(100);
    }
    closegraph();
}
void interfaceGraphique::drawGraphOV(vector<vector<int>> adjMatrix) const {

    int numNodes = adjMatrix.size() - 1; // exclure la première ligne et la première colonne
    // request autodetection
    int gdriver = DETECT, gmode, errorcode;
    int xmax, ymax;

    // initialize graphics and local variables

    initgraph(&gdriver, &gmode, "");

    int nodeRadius = 25;
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    // Dessiner les nœuds
    for (int i = 0; i < numNodes; i++) {
        int angle = i * 360 / numNodes;
        int x = centerX + 200 * cos(angle * M_PI / 180);
        int y = centerY + 200 * sin(angle * M_PI / 180);
        setcolor(15);
        circle(x, y, nodeRadius);
        char nodeNum[10];
        sprintf(nodeNum, "%d", i + 1);
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(x - textwidth(nodeNum) / 2, y - textheight(nodeNum) / 2, nodeNum);
    }
    vector<int>couleur(16);
    for(int i=0;i<couleur.size();i++)
    {

        couleur[i] = i;

    }
    couleur[0]=12;
    couleur[1]=14;
        // Dessiner les arêtes
   // Dessiner les arêtes
// Dessiner les arêtes
// Dessiner les arêtes
for (int i = 0; i < numNodes; i++) {
    for (int j = 0; j < numNodes; j++) {
        if (adjMatrix[i + 1][j + 1] != -1 && i!=j) {
            int x1 = centerX + 200 * cos(i * 360 / numNodes * M_PI / 180);
            int y1 = centerY + 200 * sin(i * 360 / numNodes * M_PI / 180);
            int x2 = centerX + 200 * cos(j * 360 / numNodes * M_PI / 180);
            int y2 = centerY + 200 * sin(j * 360 / numNodes * M_PI / 180);
            int dx = x2 - x1;
            int dy = y2 - y1;
            double length = sqrt(dx * dx + dy * dy);
            double unitDx = dx / length;
            double unitDy = dy / length;
            double arrowSize = 20;
            int arrowX = x2 - unitDx * arrowSize;
            int arrowY = y2 - unitDy * arrowSize;
            setcolor(couleur[i]);
            line(x1, y1, arrowX, arrowY);
            char weight[10];
            sprintf(weight, "%d", adjMatrix[i + 1][j + 1]);
            settextstyle(3, HORIZ_DIR, 2);
            // on peut ajuster le 20 pour controler la distabce entre l'arête et le poid
            int weightX = (x1 + x2) / 2 + 20 * cos((i + j) * 360 / (2 * numNodes) * M_PI / 180);
            int weightY = (y1 + y2) / 2 + 20 * sin((i + j) * 360 / (2 * numNodes) * M_PI / 180);
            outtextxy(weightX - textwidth(weight) / 2, weightY - textheight(weight) / 2, weight);
            int arrowTip1X = arrowX + unitDy * arrowSize / 3;
            int arrowTip1Y = arrowY - unitDx * arrowSize / 3;
            int arrowTip2X = arrowX - unitDy * arrowSize / 3;
            int arrowTip2Y = arrowY + unitDx * arrowSize / 3;
            setfillstyle(SOLID_FILL, couleur[i]);
            fillellipse(arrowX, arrowY, 6, 6);
            line(arrowX, arrowY, arrowTip1X, arrowTip1Y);
            line(arrowX, arrowY, arrowTip2X, arrowTip2Y);
        }
    }
}



    // Attendre un clic de souris pour fermer la fenêtre graphique
    while (!kbhit()) {
        delay(100);
    }
    closegraph();
}
void interfaceGraphique::drawGraphONV(vector<vector<int>> adjMatrix) const {
    int numNodes = adjMatrix.size() - 1; // exclure la première ligne et la première colonne
    // request autodetection
    int gdriver = DETECT, gmode, errorcode;
    int xmax, ymax;

    // initialize graphics and local variables

    initgraph(&gdriver, &gmode, "");

    int nodeRadius = 25;
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    // Dessiner les nœuds
    for (int i = 0; i < numNodes; i++) {
        int angle = i * 360 / numNodes;
        int x = centerX + 200 * cos(angle * M_PI / 180);
        int y = centerY + 200 * sin(angle * M_PI / 180);
        setcolor(15);
        circle(x, y, nodeRadius);
        char nodeNum[10];
        sprintf(nodeNum, "%d", i + 1);
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(x - textwidth(nodeNum) / 2, y - textheight(nodeNum) / 2, nodeNum);
    }
    vector<int>couleur(16);
    for(int i=0;i<couleur.size();i++)
    {

        couleur[i] = i;

    }
    couleur[0]=12;
    couleur[1]=14;
        // Dessiner les arêtes
   // Dessiner les arêtes
// Dessiner les arêtes
// Dessiner les arêtes
for (int i = 0; i < numNodes; i++) {
    for (int j = 0; j < numNodes; j++) {
        if (adjMatrix[i + 1][j + 1] != -1) {
            int x1 = centerX + 200 * cos(i * 360 / numNodes * M_PI / 180);
            int y1 = centerY + 200 * sin(i * 360 / numNodes * M_PI / 180);
            int x2 = centerX + 200 * cos(j * 360 / numNodes * M_PI / 180);
            int y2 = centerY + 200 * sin(j * 360 / numNodes * M_PI / 180);
            int dx = x2 - x1;
            int dy = y2 - y1;
            double length = sqrt(dx * dx + dy * dy);
            double unitDx = dx / length;
            double unitDy = dy / length;
            double arrowSize = 20;
            int arrowX = x2 - unitDx * arrowSize;
            int arrowY = y2 - unitDy * arrowSize;
            setcolor(couleur[i]);
            line(x1, y1, arrowX, arrowY);
            char weight[10];
            sprintf(weight, "%d", adjMatrix[i + 1][j + 1]);
            settextstyle(3, HORIZ_DIR, 2);
            // on peut ajuster le 20 pour controler la distabce entre l'arête et le poid
            int weightX = (x1 + x2) / 2 + 20 * cos((i + j) * 360 / (2 * numNodes) * M_PI / 180);
            int weightY = (y1 + y2) / 2 + 20 * sin((i + j) * 360 / (2 * numNodes) * M_PI / 180);
          //  outtextxy(weightX - textwidth(weight) / 2, weightY - textheight(weight) / 2, weight);
            int arrowTip1X = arrowX + unitDy * arrowSize / 3;
            int arrowTip1Y = arrowY - unitDx * arrowSize / 3;
            int arrowTip2X = arrowX - unitDy * arrowSize / 3;
            int arrowTip2Y = arrowY + unitDx * arrowSize / 3;
            setfillstyle(SOLID_FILL, couleur[i]);
            fillellipse(arrowX, arrowY, 6, 6);
            line(arrowX, arrowY, arrowTip1X, arrowTip1Y);
            line(arrowX, arrowY, arrowTip2X, arrowTip2Y);
        }
    }
}
    // Attendre un clic de souris pour fermer la fenêtre graphique
    while (!kbhit()) {
        delay(100);
    }
    closegraph();
}


