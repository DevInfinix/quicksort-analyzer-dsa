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
struct student backup[MAX];
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
		r = (x.id > y.id) - (x.id < y.id);
	}
	else if (field == 2)
	{
		r = strcmp(x.name, y.name);
	}
	else
	{
		r = (x.marks > y.marks) - (x.marks < y.marks);
	}

	if (order == 2)
		r = -r;

	return r;
}

int partition(struct student a[], int lb, int ub)
{
	int dn, up, p;
	struct student val, temp;

	partitions++;

	if (pivotType == 1)
		p = lb;
	else if (pivotType == 2)
		p = ub;
	else
		p = (lb + ub) / 2;

	if (p != lb)
	{
		temp = a[p];
		a[p] = a[lb];
		a[lb] = temp;
		swaps++;
	}

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
		{
			temp = a[dn];
			a[dn] = a[up];
			a[up] = temp;
			swaps++;
		}
	}

	if (up != lb)
	{
		temp = a[lb];
		a[lb] = a[up];
		a[up] = temp;
		swaps++;
	}

	printf("Pivot: ");
	if (field == 1)
		printf("%d", val.id);
	else if (field == 2)
		printf("%s", val.name);
	else
		printf("%d", val.marks);
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

void addRecord(void)
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

	backup[n] = rec[n];
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

	copy(rec, backup, n);
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
