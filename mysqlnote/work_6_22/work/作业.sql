

create database buildCompany;

use buildCompany;

create table project(
	projectNum int not null ,
    projectName varchar(32) ,
    primary key (projectNum)
);

create table worker(
	workerId int not null,
    name varchar(10),
    sex varchar(1),
    job varchar(10),
    primary key (workerId)
);

create table projectDetail(
	projectNum int,
    workerId int  not null,
    primary key (workerId)
);

create table workerSalary(
	workerId int not null,
    workTime int,
    salary int,
    primary key (workerId)
);

create table salaryRate(
	job varchar(10),
    rate int ,
    primary key (job)
);