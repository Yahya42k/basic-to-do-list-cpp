#include<iostream>
#include<vector>
#include<string>
#include<fstream>

void showTasks(std::vector<std::string> &tasks){
int i=1;
    for(auto ts:tasks){
        std::cout<<i<<"."<<ts<<std::endl;
    }
}



int main(){

std::vector<std::string> tasks;
std::string task;
char option;

std::fstream inputfile("tasks.txt");
if(inputfile.is_open())
while(getline(inputfile,task)){
    tasks.push_back(task);
}else{
    std::cout<<"Cannot open file"<<std::endl;
}

inputfile.close();

do{
    std::cout<<"Enter your choice\n";
    std::cout<<"Enter A to add new tasks "<<std::endl;
    std::cout<<"Enter V to view all tasks "<<std::endl;
    std::cout<<"Enter E to exit"<<std::endl;
    std::cin>>option;
    std::cin.ignore();

    switch(option){
        case 'a':
        case 'A':
        std::cout<<"Enter task to add\n";
        std::getline(std::cin,task);
        tasks.push_back(task);
        break;
        case 'v':
        case 'V':
        showTasks(tasks);
        break;
        default:
        break;

    }



}while(option!='e'&&option!='E');

std::fstream outputfile("tasks.txt");

if(outputfile.is_open()){
    for(auto i=tasks.begin();i<tasks.end();i++){
        outputfile<<*i<<std::endl;
    }
}else{
    std::cout<<"Could not write task to the outputfile.\n";
}
outputfile.close();


    return 0;
}