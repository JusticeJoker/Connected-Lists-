#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// patient struct
typedef struct patient
{
	char name[50+1];
	int age;
	int nhsId;
	struct patient *next;
	
} Patient;

// constant
const Patient EMPTY_PATIENT;

// enumerator
typedef enum boolean
{ false, true } bool;


// add patient to queue
void enqueue(Patient **head, Patient **tail, bool *isEmpty, char *newPatientName, int newPatientAge, int newPatientNHSID)
{
	// variables
	Patient *newPatient;
	
	// indicate size of newPatient
	newPatient = (Patient*) malloc(sizeof(Patient));
	
	// Patient information
	strcpy(newPatient->name, newPatientName);
	newPatient->age = newPatientAge;
	newPatient->nhsId = newPatientNHSID;
	newPatient->next = NULL;
	
	// add newPatient to the list
	if (*isEmpty)
	{
		*head = newPatient;
		*tail = newPatient;
		*isEmpty = false;
	}
	else
	{
		// put the element in the queue tail
		(**tail).next = newPatient;
		(*tail) = newPatient;
	}
}

// remove a patient from the queue
Patient dequeue(Patient **head, bool *isEmpty)
{
	// variables
	Patient patient;
	
	// cannot remove patient if the queue is empty
	if (*isEmpty)
	{ 
		printf("Sorry, but queue is empty...");
		return EMPTY_PATIENT;
	}
	
	// save the patient to dequeue
	patient = **head;
	
	// update the queue
	*head = (**head).next;
	*isEmpty = (*head == NULL);
	
	// return patient removed from queue
	return patient;
}

// use that subroutine to see the next patient
void peek(Patient *head, int empty)
{
    // variables
    Patient *actual;

    // save the patient
    actual = head;

    // case queue is empty
    if (empty == 1)
    {
        printf("=====ERROR=====\nThe Queue is Empty....\n\n");
        return;
    }

    // case next patient don't exist
    if (actual->next == NULL)
    {
        printf("=====ERROR=====\nDon't have next patient...\n\n");
        return;
    }

    // show next Patient
    actual = actual->next;
    printf("\n\nNext Patient:\nNHS Id: %d\nAge: %d\nName: %s\n\n", actual->nhsId, actual->age, actual->name);
}

// count patients in the queue
void averageAge(Patient *head, bool isEmpty)
{
	// variables
	Patient *actual;
	float avgAge, totalAge = 0, counter = 0;
	
	// in case queue is empty
	if (isEmpty)
	{
		printf("Sorry, but queue is empty...");
		return;
	}
		
	// save the patient to the dequeue
	actual = head;
	
	// calculate the age and goes through queue
	while (actual != NULL)
	{
		
		// go through all ages
		totalAge += actual->age;
		counter++;
		
		// jump to next patient
		actual = actual->next;
	}
	
	// calculate the average of all ages
	avgAge = totalAge / counter;
	
	// print the average
	printf("Average of all Ages: %0.1f\n\n", avgAge);
		
}

// show all students in the queue
void show( char *title, Patient *head, bool isEmpty)
{
	// variables
	Patient *actual;
	int orderNumber = -1;
	int counter = 1;
	
	// title
	printf(" \n%s\n\n", title);
	printf(" size of (Patient): %d\n\n", sizeof(Patient));
	
	// san't remove if the queue is empty
	if (isEmpty)
	{
		printf("Sorry, but queue is empty...");
		return;
	}
	
	// save the patients to the dequeue
	actual = head;
	
	// show patients
	while(actual != NULL)
	{
		//increase orderNumber
		orderNumber++;
		
		// present patients info
		printf(" (FIFO number: %d) Ticket Number: %d, Age: %d, Name: %s\n",
			orderNumber, counter, actual->age, actual->name);
			
		// move to the next element
		counter++;
		actual = actual->next;		
	}
	
}

int main(int argc, char *argv[]) {
	
	Patient *head;
	Patient *tail;
	bool isEmpty;
	Patient patient1, patient2, patient3;
	
	// initializing
	head = NULL;
	tail = NULL;
	isEmpty = true;
	
	// enqueue first Patient 
	enqueue(&head, &tail, &isEmpty, "Joaquim Alfredo", 55, 234687958);
	
	// enqueue second Patient 
	enqueue(&head, &tail, &isEmpty, "Maria Leitao", 23, 234583956);
	
	// enqueue third Patient 
	enqueue(&head, &tail, &isEmpty, "Roberto Candeias", 44, 234839027);
	
	// enqueue forth Patient 
	enqueue(&head, &tail, &isEmpty, "Nuno Godofredo", 61, 234285746);
	
	printf("=====================================================\n");
	// show all patients in the queue from the head to tail
	show(" Patients in the queue", head, isEmpty);
	printf("\n=====================================================\n");
	
	// show next element after the queue 
	peek(head, isEmpty);
	printf("=====================================================\n\n");
	
	// show average agr of the patients
	averageAge(head, isEmpty);	
	printf("=====================================================\n\n");
	
	return 0;
}
