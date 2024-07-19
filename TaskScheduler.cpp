#include<iostream>
#include<string>
#include<cstddef>

//STRUCT TO REPRESENT A TASK
struct Task{
	std::string name;
	std::string dueDate;
	int priority;
	Task* next;
};

//CLASS TO MANAGE TASKS THROUGH A LINKED LIST
class TaskScheduler{
	private:
		Task* head;
		
		public:
			//Constructor to initialize an empty linked list
			TaskScheduler(): head(nullptr){}
			
			//Method to add a task to the scheduler
			void addTask(const std::string& name,const std::string& dueDate,int priority){
				//Create a new task
				Task* newTask=new Task{ name,dueDate,priority,nullptr};
				
				//Insert the task into the linked list based on priority
				if(!head || priority>head->priority){
					newTask->next=head;
					head=newTask;
				} 
				else{
				Task* current=head;
				while(current->next && priority<=current->next->priority){
					current=current->next;
			}
			newTask->next=current->next;
			current->next=newTask;
				}
			}
			
			//Method to remove a task from the scheduler
			void removeTask(const std::string& taskName){
				if(!head){
					std::cout<<"Task Scheduler is empty.\n";
					return;
				}
				Task* current=head;
				Task* prev=nullptr;
				
				//Search the task by name
				while(current && current->name!=taskName){
					prev=current;
					current=current->next;
				}
				
				//If the task is not found then print a message and return
				if(!current){
					std::cout<<"Task not found.\n";
					return;
				}
				
				//Adjust pointers to remove the task from the linked list
				if(!prev){
					head=current->next;
				}
				else{
					prev->next=current->next;
				}
				
				//Delete the task and print a success message
				delete current;
				std::cout<<"Task removed successfully.\n";
			}
			
			//Method to display all task in the scheduler
			void displayTasks(){
				if(!head){
					std::cout<<"Task scheduler is empty.\n";
					return;
				}
				Task* current=head;
				//Traverse the linked list and print task details
				while(current){
					std::cout<<"Task: "<<current->name<<", Due Date: "<<current->dueDate
					         <<", Priority: "<<current->priority<<"\n";
					current=current->next;         
				}
			}
};

int main(){
	//Create an instance of the Task Scheduler class 
	TaskScheduler scheduler;
	
	char choice;
	do{
		//Prompt the user to add,remove,or quit
		std::cout<<"Enter 'A' to add a task or 'R' to remove a task (or 'Q' to quit):";
		std::cin>>choice;
		
	if(choice=='A'||choice=='a'){
		std::string name,dueDate;
		int priority;
		
		//Prompt the user to enter task details
		std::cout<<"Enter Task Name: ";
		std::cin.ignore();
		std::getline(std::cin,name);
		
		std::cout<<"Enter Due Date: ";
		std::getline(std::cin,dueDate);
		
		std::cout<<"Enter Priority: ";
		std::cin>>priority;
		
		//Add the task to the scheduler
		scheduler.addTask(name,dueDate,priority);
	}
	else if(choice=='R' || choice=='r'){
	std::string taskName;
	
	//Prompt the user to enter task name to remove
	std::cout<<"Enter Task Name To Remove: ";
	std::cin.ignore(); //consume a newline character left by previous input
	std::getline(std::cin,taskName);	
	
	//Remove the task from the scheduler
	scheduler.removeTask(taskName);
}

	//Display the current list of tasks
	std::cout<<"Current tasks: \n";
	scheduler.displayTasks();	
	}
	while(choice!='Q' && choice!='q');
	return 0;
}
