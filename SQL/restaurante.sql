create table Pessoa (
    CPF number(11) primary key not null ,
    nome varchar(10) not null unique,
    endereço varchar (10) not null,
    sexo char (1) not null,
    data_nasc date not null 
                    )
create table Cozinheiro (
    CPF number (11),
    PRIMARY KEY(cpf),
    FOREIGN KEY (cpf) REFERENCES Pessoa)



create table Receita (
                Codigo number (1) not null ,
                nome varchar (10) not null,
                descricao varchar (15)  not null,
                primary key (codigo)
                )

DROP TABLE cria ; 
                
create table Cria (
                CPF number(11) not null,
                Codigo number (1) not null,
                data date,
                PRIMARY KEY(cpf, codigo),
                FOREIGN KEY (cpf) REFERENCES cozinheiro (cpf),
                FOREIGN KEY (codigo) REFERENCES receita (codigo) 
                )


create table Restaurante (
                cnpj number(11) primary key not null,
                nome varchar(10) not null,
                endereço varchar (10) not null,
                cidade varchar(10) not null
                )
                
create table Serve (
                cnpj number(11),
                Codigo number (1) primary key not null, 
                preço number (3),

insert into Pessoa (CPF, nome, endereço, sexo, data_nasc) 
values (49301544806, 'Maria Carolina Sirio', ' Rua da alegria 344-8788','F', to_date('1/2/1997','dd/mm/yyyy'));


insert into Pessoa (CPF, nome, endereço, sexo, data_nasc) 
values (49301544206, 'Pedro Paulo Canopo', 'Rua da alegria 274-9018', "M",to_date('3/8/1996','dd/mm/yyyy'));

insert into Pessoa (CPF, nome, endereço, sexo, data_nasc) 
values (49301544801, 'Augusto Lemos Vega', 'Rua da alegria 722-1300', 'M',to_date('12/11/1998','dd/mm/yyyy'));

insert into Pessoa (CPF, nome, endereço, sexo, data_nasc) 
values (49301244806, 'Monica Silveira Capela',  'Rua da alegria 212-7938','F', to_date('30/12/1997','dd/mm/yyyy'));

insert into Pessoa (CPF, nome, endereço, sexo, data_nasc) 
values (49301534706, 'Almir Altair',  'Rua da alegria 220-6022', 'M',to_date('3/10/1996','dd/mm/yyyy'));

insert into Pessoa (CPF, nome,endereço, sexo, data_nasc) 
values (48301644206, 'Leonardo Guimaraes Rigel', 'Rua da alegria 12','M',to_date('17/7/1997','dd/mm/yyyy'));

insert into Pessoa (CPF, nome,endereço, sexo, data_nasc) 
values (42308540102, 'Beatriz Bellatrix',  'Rua da alegria q312', 'F', to_date('18/9/1998','dd/mm/yyyy'));

insert into Pessoa (CPF, nome,endereço, sexo, data_nasc) 
values (42378540102, 'Carlos Regulos',  'Rua da alegria 345', 'M',to_date('1/3/1997','dd/mm/yyyy'));

insert into Pessoa (CPF, nome, endereço, sexo, data_nasc) 
values (42308520102, 'Joana Aldebaran','Rua da alegria 6346','F', to_date('3/8/1996','dd/mm/yyyy'));

insert into Pessoa (CPF, nome, endereço, sexo, data_nasc) 
values (42308520102, 'Matias Agena', 'Rua da alegria 0908', 'M', to_date('3/8/1996','dd/mm/yyyy'));
