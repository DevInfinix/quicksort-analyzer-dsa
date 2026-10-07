#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct student
{
	int id;
	char name[30];
	int marks;
};

struct student rec[MAX];
struct student original[MAX];
int n = 0;

int field = 1;
int order = 1;
int pivotType = 1;

long comparisons, swaps, calls, partitions;

int compare(struct student x, struct student y)
{
	int r;
	comparisons++;

	if (field == 1)
	{
		if (x.id < y.id)
			r = -1;
		else if (x.id > y.id)
			r = 1;
		else
			r = 0;
	}
	else if (field == 2)
	{
		r = strcmp(x.name, y.name);
	}
	else
	{
		if (x.marks < y.marks)
			r = -1;
		else if (x.marks > y.marks)
			r = 1;
		else
			r = 0;
	}

	if (order == 2)
		r = -r;

	return r;
}

void swap(struct student *x, struct student *y)
{
	struct student temp;
	temp = *x;
	*x = *y;
	*y = temp;
	swaps++;
}

void printKey(struct student s)
{
	if (field == 1)
		printf("%d", s.id);
	else if (field == 2)
		printf("%s", s.name);
	else
		printf("%d", s.marks);
}

int partition(struct student a[], int lb, int ub)
{
	int dn, up, p;
	struct student val;

	partitions++;

	if (pivotType == 1)
		p = lb;
	else if (pivotType == 2)
		p = ub;
	else
		p = (lb + ub) / 2;

	if (p != lb)
		swap(&a[p], &a[lb]);

	val = a[lb];
	dn = lb + 1;
	up = ub;

	while (dn <= up)
	{
		while (dn <= ub && compare(a[dn], val) <= 0)
			dn++;
		while (compare(a[up], val) > 0)
			up--;
		if (dn < up)
			swap(&a[dn], &a[up]);
	}

	if (up != lb)
		swap(&a[lb], &a[up]);

	printf("Pivot: ");
	printKey(val);
	printf("\tLeft: %d\tRight: %d\n", up - lb, ub - up);

	return up;
}

void quicksort(struct student a[], int lb, int ub)
{
	int p;

	calls++;

	if (lb < ub)
	{
		p = partition(a, lb, ub);
		quicksort(a, lb, p - 1);
		quicksort(a, p + 1, ub);
	}
}

void resetCount()
{
	comparisons = 0;
	swaps = 0;
	calls = 0;
	partitions = 0;
}

void copy(struct student to[], struct student from[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		to[i] = from[i];
}

void addRecord()
{
	if (n == MAX)
	{
		printf("Record list is full.\n");
		return;
	}

	printf("Enter ID: ");
	scanf("%d", &rec[n].id);
	printf("Enter Name: ");
	scanf("%29s", rec[n].name);
	printf("Enter Marks: ");
	scanf("%d", &rec[n].marks);

	original[n] = rec[n];
	n++;
	printf("Record added.\n");
}

void showRecords()
{
	int i;

	if (n == 0)
	{
		printf("No records.\n");
		return;
	}

	printf("\nID\tName\t\tMarks\n");
	printf("-------------------------------\n");
	for (i = 0; i < n; i++)
		printf("%d\t%-12s\t%d\n", rec[i].id, rec[i].name, rec[i].marks);
}

void chooseField()
{
	printf("\nSort by:\n1. ID\n2. Name\n3. Marks\nEnter choice: ");
	scanf("%d", &field);
	if (field < 1 || field > 3)
		field = 1;

	printf("\nOrder:\n1. Ascending\n2. Descending\nEnter choice: ");
	scanf("%d", &order);
	if (order < 1 || order > 2)
		order = 1;
}

void choosePivot()
{
	printf("\nPivot:\n1. First\n2. Last\n3. Middle\nEnter choice: ");
	scanf("%d", &pivotType);
	if (pivotType < 1 || pivotType > 3)
		pivotType = 1;
}

void printCount()
{
	printf("\nComparisons     : %ld\n", comparisons);
	printf("Swaps           : %ld\n", swaps);
	printf("Partitions      : %ld\n", partitions);
	printf("Recursive calls : %ld\n", calls);
}

void sortRecords()
{
	if (n == 0)
	{
		printf("No records to sort.\n");
		return;
	}

	chooseField();
	choosePivot();

	copy(rec, original, n);
	resetCount();

	printf("\nPartition details:\n");
	quicksort(rec, 0, n - 1);

	printf("\nSorted records:");
	showRecords();
	printCount();
}

int main()
{
	int ch;

	do
	{
		printf("\n===== QUICK SORT RECORD ORGANIZER =====\n");
		printf("1. Add Record\n");
		printf("2. Display Records\n");
		printf("3. Sort Records\n");
		printf("4. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1: addRecord(); break;
		case 2: showRecords(); break;
		case 3: sortRecords(); break;
		case 4: printf("Exiting...\n"); break;
		default: printf("Invalid choice.\n");
		}
	} while (ch != 4);

	return 0;
}
