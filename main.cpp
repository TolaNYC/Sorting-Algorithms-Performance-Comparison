#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// CONSTANTS
const unsigned int SMALL = 100;
const unsigned int BIG = 1000;


// GLOBAL VARIABLES
int nrComparisons = 0;
int nrSwaps = 0;
int total = 0;
int nLog = 0;
int nxN = 0;
int range = 0;
int selection = 0;
string sortName;
string arrayOrder;
int smallArray[SMALL], bigArray[BIG];
int caseNr, sortingNr, aSize, sizeOption;

//******* FUNCTION PROTOTYPES *******

// GENERATING ARRAYS
void randomFill(int [], int);
void almostSortedAscFill(int[], int);
void almostSortedDesFill(int[], int);
void unsortedLastTenFill(int[], int);

// SORTING ALGORITHMS
void insertionSort(int[], int);
void selectionSort(int [], int);
void mergeSort(int[], int, int);
void merge(int [], int, int, int);
void quickSort(int[], int, int);
int partition(int[], int, int);
void heapSort(int[], int);

// OTHER FUNCTIONS
void swap(int *, int *);
void printArray(int[], int);
void displayStats(int);
void displaySortingOptions();
void displayMainMenu();
void displayHeader();
void displayOrder();
void manualTesting();
void displayConclusions();
void dataTable();
void mainMenu();
void fillArray(int, int, int[]);
void sortArray(int[],int);
void makeArray(int[], int);
void generatedArraysMenu();
void update();


int main() {

    string go;

    do {
        mainMenu();
        cin >> selection;

        switch (selection) {
            case 1:
                dataTable();
                break;
            case 2:
                manualTesting();
                break;
            case 3:
                displayConclusions();
                break;
              default:
                break;
        }

        cout<<"\nDO YOU WANT TO GO BACK TO THE MAIN MENU? yes/no: ";
        cin>>go;

    }
    while (go=="yes"||go=="Yes"||go=="YES"||go=="1");

    return 0;

}

void dataTable() {

    string answer;

    //******   AUTOMATICALLY GENERATING DATA ON THE CONSOLE  *************

    // CASES FOR ARRAY-SIZES
    for (int k = 1; k <= 2; k++) {
        sizeOption = k;
        displayHeader();


        // CASES FOR ARRAY CONFIGURATIONS
        for (int i = 1; i <= 4; i++) {
            caseNr = i;
            if (sizeOption == 1) {
                fillArray(caseNr, SMALL, smallArray);
                displayOrder();

                // CASES FOR SORTING ALGORITHMS (SMALL ARRAY)
                for (int j = 1; j <= 5; j++) {
                    sortingNr = j;
                    fillArray(caseNr, SMALL, smallArray);
                    sortArray(smallArray, SMALL);
                    cout << setw(25) << left << sortName << setw(10) << left << nrComparisons << setw(10) << nrSwaps
                         << setw(10) << left << total << setw(10) << left << nLog << setw(7) << right << nxN
                         << endl;
                }
            } else {
                fillArray(caseNr, BIG, bigArray);
                displayOrder();

                // CASES FOR SORTING ALGORITHMS (BIG ARRAY)
                for (int j = 1; j <= 5; j++) {
                    sortingNr = j;
                    fillArray(caseNr, BIG, bigArray);
                    sortArray(bigArray, BIG);
                    cout << setw(25) << left << sortName << setw(10) << left << nrComparisons << setw(10) << nrSwaps
                         << setw(10) << left << total << setw(10) << left << nLog << setw(7) << right << nxN
                         << endl;

                }
            }
        }
    }
}


//***********************  MANUAL TESTING  **************************************

void manualTesting(){
    string answer;

    do {

        // DISPLAY MAIN MENU
        displayMainMenu();

        // CHOOSE THE CASE FOR TESTING
        cin >> caseNr;
        if (caseNr < 1 || caseNr > 5) {
            break;
        }
        if (caseNr > 0 && caseNr <= 4) {
            generatedArraysMenu();

            // CHOOSE THE SIZE
            cin >> sizeOption;

            switch (sizeOption) {
                case 1:

                    //FUNCTION CALLS ON SMALL ARRAY
                    fillArray(caseNr, SMALL, smallArray);
                    printArray(smallArray, SMALL);
                    displaySortingOptions();
                    cin >> sortingNr;
                    sortArray(smallArray, SMALL);
                    printArray(smallArray, SMALL);
                    displayStats(SMALL);


                    break;
                case 2:

                    //FUNCTION CALLS ON BIG ARRAY
                    fillArray(caseNr, BIG, bigArray);
                    printArray(bigArray, BIG);
                    displaySortingOptions();
                    cin >> sortingNr;
                    sortArray(bigArray, BIG);
                    printArray(bigArray, BIG);
                    displayStats(BIG);


                    break;
                default:
                    break;
            }

        }

        // MANUALLY CREATING THE ARRAY
        if (caseNr == 5) {
            cout << "ENTER THE SIZE OF THE ARRAY: ";
            cin >> aSize;
            int tempArray[aSize];
            makeArray(tempArray, aSize);
            printArray(tempArray, aSize);
            displaySortingOptions();
            cin >> sortingNr;
            sortArray(tempArray, aSize);
            printArray(tempArray, aSize);
            displayStats(aSize);
            // update(aSize, tempArray);
        }

        cout << "\nDO YOU WANT TO CONTINUE MANUAL TESTING ? (yes/Yes/YES/1) : ";
        cin >> answer;
    } while ((answer == "YES") || (answer == "Yes") || (answer == "yes") || (answer == "1"));


}


// ------------------   SORTING ALGORITHMS ---------------------
// ************************ INSERTION SORT *********************

//insertionSort(s,length);
void insertionSort(int array[], int length) {


    for (int i = 1; i < length; i++) {

        int currentRightmost = array[i];
        int j = i - 1;

        // BEST CASE: (N-1) COMPARISONS (When we don't enter the inner loop)
        if (array[i] > array[j]) {
            nrComparisons++;
        }

        while (j >= 0 && array[j] > currentRightmost) {
            swap(&array[j + 1], &array[j]);

            //WORST CASE-(N*(N-1))/2 COMPARISONS AND (N*(N-1))/2 SWAPS
            // (nrSwaps = nrComparisons, array in reverse order)

            nrSwaps++;
            nrComparisons++;
            j--;

            //COUNTING THE LAST COMPARISON WITH THE RIGHTMOST ELEMENT OF THE SORTED
            // ARRAY OR WHETHER WE REACHED THE LEFTMOST END if (j<0 COMPARISON)
            if ((j < 0) || (array[j] <= currentRightmost)) {
                nrComparisons++;
            }
        }

        array[j + 1] = currentRightmost;

    }
}

// *********************** SELECTION SORT *********************

//selectionSort(s,length);
void selectionSort(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {

        int smallest = i;

        for (int j = i + 1; j < length; j++) {
            // ALWAYS (N*(N-1))/2) COMPARISONS
            nrComparisons++;
            if (array[j] < array[smallest]) {
                smallest = j;
            }
        }

        // WORST CASE: (N-1) SWAPS, CAN BE IMPROVED SLIGHTLY!
        swap(&array[i], &array[smallest]);
        nrSwaps++;


        //WHEN SWAPS ARE EXPENSIVE
        // (BEST CASE: REDUCES SWAPS TO 0 WHEN ARRAY IS SORTED)
        /*  if(min!=i) {
            swap(&array[i], &array[min]);
            nrSwaps++;
            }
        */

    }
}


// *********************** MERGE SORT *********************

//mergeSort(smallArray, 0, length-1);
void mergeSort(int arr[], int l, int r) {
    if (l < r) {

        int m = l + (r - l) / 2;

        //SORT LEFT AND RIGHT HALF AND MERGE
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


void merge(int arr[], int l, int m, int r) {

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    // COPYING THE DATA IN THE LEFT AND RIGHT ARRAY
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        nrSwaps++;
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        nrSwaps++;
    }
    // COUNTERS FOR LEFT,RIGHT AND TEMP ARRAY
    i = 0;
    j = 0;
    k = l;

    // MERGE TWO ARRAYS
    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {

            arr[k] = R[j];
            j++;
        }
        k++;

        //COMPARISONS FROM PREVIOUS MERGE CALLS-> LOG(N-1)*(N/2) + COMPARISONS FROM LAST MERGE CALL (N/2) to (N-1))
        nrComparisons++;
    }

    //GET THE REST OF THE ELEMENTS FROM LEFT ARRAY
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;

    }

    //GET THE REST OF THE ELEMENTS FROM RIGHT ARRAY
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}



// ******************* QUICK SORT *********************

//quickSort(s,0,length-1);
void quickSort(int arr[], int low, int high) {
    if (low < high) {

        // FIND RIGHT POSITION FOR THE PIVOT
        int pi = partition(arr, low, high);

        // SORT THE LEFT AND THE RIGHT OF THE PIVOT
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int partition(int arr[], int low, int high) {

    // CHOOSING A PIVOT
    // WORST CASE - ~N^2 PIVOT IS THE LARGEST OR SMALLEST ELEMENT IN THE ARRAY
    // BEST CASE - EVERY TIME THE PIVOT INDEX ENDS UP BEING THE MIDDLE ELEMENT OF THE ARRAY
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {

        // COMPARING ALL THE ELEMENTS ON THE LEFT OF THE PIVOT WITH THE PIVOT
        nrComparisons++;
        if (arr[j] < pivot) {
            i++;

            swap(&arr[i], &arr[j]);
            nrSwaps++;

            // IF SWAPS ARE EXPENSIVE OR ARRAY IS ALMOST SORTED
            /*   if (i != j) {
                   swap(&arr[i], &arr[j]);
                   nrSwaps++;
               }*/

        }
    }

    // -ANOTHER WAY TO COUNT SWAPS
    //  COUNTING THE NR OF TIMES i-counter MOVES TO THE RIGHT AS NR OF SWAPS
    //  AND ADDING THE SWAP OF (i+1) WITH THE PIVOT TO THE TOTAL FOR EACH CALL

    /*if(i>-1) {
        nrSwaps += (i-low)+1;
    }*/

    swap(&arr[i + 1], &arr[high]);
    nrSwaps++;
    return i + 1;
}


// ********************** HEAP SORT *********************

//heapSort(smallArray, SMALL);
void heapSort(int arr[], int N) {

    // CHECKING IF THE HEAP IS EMPTY
    if (N == 0)
        return;

    int t, n = N, parent = N / 2, index, child;


    // LOOPING UNTIL THE ARRAY IS SORTED
    while (1) {

        if (parent > 0) {
            // SAVE THE VALUE OF THE PARENT NODE
            t = arr[--parent];

        } else {
            //MAKE THE HEAP SMALLER
            n--;
            //IF ONLY ONE NODE
            if (n == 0) {
                return;
            }
            // SWAP THE ROOT NODE WITH THE LAST NODE
            t = arr[n];
            arr[n] = arr[0];
            nrSwaps++;
        }

        index = parent;
        child = index * 2 + 1;

        // HEAPIFY THE ARRAY

        while (child < n) {

            //~ N*(LOG N)
            //CHECK FOR THE LARGEST CHILD
            nrComparisons++;
            if (child + 1 < n && arr[child + 1] > arr[child]) {
                child++;
            }

            nrComparisons++;

            if (arr[child] > t) {

                //SWAP THE ROOT WITH THE CHILD
                arr[index] = arr[child];
                nrSwaps++;

                // UPDATE INDEX
                index = child;
                // UPDATE CHILD
                child = index * 2 + 1;


            }
                // BREAK IF THE PARENT IS BIGGER THAN THE CHILDREN
            else {
                break;
            }
        }

        //SAVE t TO THE NEW LOCATION
        arr[index] = t;

    }
}


//**** METHODS TO FILL THE ARRAYS BASED ON THE CASE ********


// CASE A
void randomFill(int array[], int length) {

    range = length;
    srand(time(0));

    for (int i = 0; i < length; i++) {

        int nr = rand() % range;
        array[i] = nr;
    }
}


// CASE B
void almostSortedAscFill(int array[], int length) {
    range = length;
    srand(time(0));
    for (int i = 0; i < length; i++) {
        // MAKE EVERY 10-ELEMENT RANDOM
        if (i % 10 == 0) {
            int nr = rand() % range;
            array[i] = nr;
        } else {
            array[i] = i;
        }

    }
}


// CASE C
void almostSortedDesFill(int array[], int length) {
    srand(time(0));

    //GENERATE THE SAME ARRAYS AS B
    almostSortedAscFill(array, length);

    //REVERSE IT
    for (int j = 0; j < length / 2; j++) {
        int k = array[j];
        array[j] = array[length - j - 1];
        array[length - j - 1] = k;
    }
}

// CASE D
void unsortedLastTenFill(int array[], int length) {
    srand(time(0));
    range = length;

    double percentage = length * 0.9;
    for (int i = 0; i < length; i++) {

        if (i >= percentage) {
            int nr = rand() % range;
            array[i] = nr;
        } else {
            array[i] = i;
        }
    }
}


// SWAP FUNCTION
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// PRINTING THE ARRAY
void printArray(int array[], int length) {
    cout << " " << endl;
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << " " << endl;
}


// CONFIGURATION CASES
void fillArray(int caseNr, int sizeOption, int array[]) {

    switch (caseNr) {
        case 1:
            randomFill(array, sizeOption);
            arrayOrder = " ARRAY OF RANDOM NUMBERS ";
            break;
        case 2:
            almostSortedAscFill(array, sizeOption);
            arrayOrder = " ALMOST SORTED ASCENDING ";
            break;
        case 3:

            almostSortedDesFill(array, sizeOption);
            arrayOrder = " ALMOST SORTED DESCENDING ";

            break;
        case 4:

            unsortedLastTenFill(array, sizeOption);
            arrayOrder = " SORTED EXCEPT LAST 10% ";
            break;
        default:
            break;
    }


}

// SORTING  ALGORITHMS
void sortArray(int array[], int size) {
    update();
    switch (sortingNr) {
        case 1:
            insertionSort(array, size);
            sortName = "INSERTION SORT ";
            break;
        case 2:
            selectionSort(array, size);
            sortName = "SELECTION SORT ";
            break;
        case 3:

            mergeSort(array, 0, size - 1);
            sortName = "MERGE SORT ";
            break;
        case 4:
            quickSort(array, 0, size - 1);
            sortName = "QUICK SORT ";
            break;
        case 5:
            heapSort(array, size);
            sortName = "HEAP SORT ";
            break;
        default:
            break;

    }

    total = nrSwaps + nrComparisons;
    nxN = (int)(((total) /(pow(size, 2))) * 100);
    nLog = (int)(((total) /(size * (log(size)))) * 100);



}

void update() {

    nrSwaps = 0;
    nrComparisons = 0;
    total = 0;
    nxN = 0;
    nLog = 0;

}


void makeArray(int tempArray[], int size) {

    int element;
    arrayOrder = "CUSTOMIZED";
    for (int i = 0; i < size; i++) {
        cout << "ENTER THE " << (i + 1) << " ELEMENT: \n";
        cin >> element;
        tempArray[i] = element;
    }

}


//********************** FUNCTIONS FOR THE DISPLAY **********************
void displayStats(int size) {


    cout << "\n\nARRAY SIZE: " << size << "  |  S-ALGORITHM: " << sortName << "  | CONFIGURATION: " << arrayOrder
         << endl;
    cout << "--------------------------------------------------------------------------------------------\n";
    cout << "THE NR OF COMPARISONS IS: " << nrComparisons << endl;
    cout << "THE NR OF SWAPS IS: " << nrSwaps << endl;
    cout << "THE TOTAL IS: " << total << endl;
    cout << "THE TOTAL IS: " << nxN << " % OF N^2 " << endl;
    cout << "THE TOTAL IS: " << nLog << " % OF N*(LOG N)"
         << endl;

    cout << "-------------------------------------------------------------------------------------------\n";

}

void displaySortingOptions() {

    cout << "\n-------------|  SORTING ALGORITHMS  |------------------------\n\n"
            "     1   -------  INSERTION SORT  ------- \n"
            "     2   -------  SELECTION SORT  ------- \n"
            "     3   --------   MERGE SORT  ---------- \n"
            "     4   --------   QUICK SORT  ---------- \n"
            "     5   ---------  HEAP SORT  ---------- \n"
            "-------------------------------------------------------------\n";
    cout << "\nENTER YOUR CHOICE 1-5 : ";
}


void displayMainMenu() {

    cout << "\n                  |   MANUAL TESTING    |                    " << endl;
    cout << " --------------------------------------------------------------\n"
            "    1               COMPLETELY RANDOM                          \n"
            " --------------------------------------------------------------\n"
            "    2        ALMOST SORTED (90%) ASCENDING ORDER               \n"
            " --------------------------------------------------------------\n"
            "    3        ALMOST SORTED (90%) DESCENDING ORDER              \n"
            " --------------------------------------------------------------\n"
            "    4               SORTED EXCEPT LAST 10%                     \n"
            " --------------------------------------------------------------\n"
            "    5            I WANT TO CREATE MY ARRAY     \n"
            " --------------------------------------------------------------\n";


    cout << "\nENTER THE CASE NR TO CONTINUE TESTING: ";
}

void generatedArraysMenu() {

    cout << "\n  -------------------------------------------------------------";
    cout << "\n   CHOOSE AN OPTION FOR FOR THE SIZE OF THE ARRAY: ";
    cout << "\n  -------------------------------------------------------------";
    cout << "\n   1   ARRAY SIZE: "<<SMALL;
    cout << "\n   2   ARRAY SIZE: "<<BIG;
    cout << "\n  -------------------------------------------------------------";
    cout << "\n  ENTER YOUR CHOICE  1/2 :";

}

void displayHeader() {


    if (sizeOption == 1) {
        cout << "\n-----------------------------|    ARRAY SIZE:  " << SMALL
             << "   |----------------------------------";
    } else {
        cout << "\n------------------------------|    ARRAY SIZE:  " << BIG
             << "   |--------------------------------";
    }
    cout << "\n////////////////////////////////////////////////////////////////////////////////////////";
}

void displayOrder() {

    cout << "\n                           |   " << arrayOrder
         << "   |                                   \n\n";
    cout << "------------------| COMPARISONS | SWAPS  |  TOTAL  | % N*(LOG N) | % N^2  |------------\n";
}

void displayConclusions() {
    cout << "\n_____________________________________________________________________________________________________"
            " \n*  Based on the data from the table, Merge Sort performs generally faster than other options \n"
            "   Merge Sort performance seems to be stable and comparisons depend slightly on the array data\n"
            "   They are always (n/2*((Log n)-1) + some number between n/2 to (n-1) in last merge call\n"
            "   However Merge Sort requires O(n)space which is a disadvantage over other in place s-algorithms \n"
            "\n"
            " * Quick Sort seems to perform very well when data is spread uniformly since it is more likely for the \n"
            "   position of the pivot to fall somewhere in the middle dividing the array in parts with similar\n"
            "   size and performing in (n*log(n)), however when the array is almost sorted the position of the \n"
            "   pivot will fall close the beginning or the end and we have to iterate over the left or the right \n"
            "   of the array being almost of length n and as a result performing (n^2).     "
            "\n"
            "\n * Like Merge Sort, Heap Sort sort performance is always n(log n) with a very small dependence on data. "
            "  \n   Where comparisons are at most 2 n*(log n) + O(n)"
            "\n"
            "\n * Insertion Sort performs very well when the array is almost sorted otherwise its performance is (n^2)"
            "\n   Insertion sort performs worse than the worst s-algorithm for the opposite case.  "
            "\n   Another disadvantage of insertion sort is the ratio comparisons:swaps, it is almost 50:50 which very"
            "\n   ineffective especially when swaps are expensive. "
            "\n\n * Selection Sort wins the 'swap challenge',being at most (n-1) it can be reduced to 0 for the best "
            "  \n   case if we decide to not swa current with min when current=min. Selection sort also wins as the worst "
            "  \n   s-algorithm for the nr of comparisons being (n*(n-1))/2) making it (n^2) forever.   "
            "\n______________________________________________________________________________________________________\n";
}

void mainMenu(){
    cout << "\n                         |  MAIN MENU  |                         \n";
    cout << "------------------------------------------------------------------\n";
    cout << "         1               SEE THE DATA TABLE \n";
    cout << "------------------------------------------------------------------\n";
    cout << "         2            TEST THE PROGRAM MANUALLY\n";
    cout << "------------------------------------------------------------------\n";
    cout << "         3               SEE THE CONCLUSIONS \n";
    cout << "------------------------------------------------------------------\n";
    cout << " \nENTER YOUR CHOICE 1/2/3 :  ";
}


////////////////////////////////////////////////////////////////////////////////////////////


// STEPS FOR MANUAL TESTING
// (1)  ************ FUNCTION CALLS TO GENERATE THE ARRAYS *******************

//   CASE A:-------------------------------
//   -Completely random
//    randomFill(smallArray, SMALL,RANGE);
//   randomFill(bigArray, BIG, RANGE);

//  CASE B:-------------------------------
//  -Almost sorted in ascending order( about 90% of items are in increasing order, 10% are random)
// almostSortedAscFill(smallArray,SMALL,RANGE);
//  almostSortedAscFill(bigArray,BIG,RANGE);

//  CASE C:---------------------------------
//  -Almost reversed -  same as b) but in reverse order
//   almostSortedDesFill(smallArray,SMALL,RANGE);
//   almostSortedDesFill(bigArray,BIG,RANGE)

//  CASE D:---------------------------------
//  -Array is sorted except for the last 10%
//   unsortedLastTenFill(smallArray,SMALL,RANGE);
//   unsortedLastTenFill(bigArray,BIG,RANGE)



// (2) *****************PRINTING THE ARRAY**********************************
//printArray(smallArray,SMALL);
// printArray(bigArray,BIG);



//* (3) *********** FUNCTION CALLS FOR SORTING ALGORITHMS *******************

// -SMALL ARRAY
// insertionSort(smallArray, SMALL);
// selectionSort(smallArray, SMALL);
// mergeSort(smallArray, 0, SMALL-1);
// quickSort(smallArray, 0, SMALL-1);
// heapSort(smallArray, SMALL);

//  -BIG ARRAY
// insertionSort(smallArray, SMALL);
// selectionSort(smallArray, SMALL);
// mergeSort(smallArray, 0, SMALL-1);
// quickSort(smallArray, 0, SMALL-1);
// heapSort(smallArray, SMALL);



// (4)  **************PRINTING THE ARRAY************************************
// printArray(smallArray,SMALL);
// printArray(bigArray,BIG);


// (5)  **************PRINTING SWAPS AND COMPARISONS************************
// cout<<"The nr of comparisons is: "<<nrComparisons<<endl;
// cout<<"The nr of swaps is: "<<nrSwaps<<endl;
