--------------------------------------------------------
--  Fichier cr�� - jeudi-avril-29-2021   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table AGENT
--------------------------------------------------------

  CREATE TABLE "NOUR"."AGENT" 
   (	"CIN_AGENT" VARCHAR2(20 BYTE), 
	"NOM_AGENT" VARCHAR2(20 BYTE), 
	"PRENOM_AGENT" VARCHAR2(20 BYTE), 
	"SEXE_AGENT" VARCHAR2(20 BYTE), 
	"DATE_DE_NAISSANCE_AGENT" VARCHAR2(20 BYTE), 
	"ADRESSE_AGENT" VARCHAR2(20 BYTE), 
	"TELEPHONE_AGENT" VARCHAR2(20 BYTE), 
	"NATIONALITE_AGENT" VARCHAR2(20 BYTE), 
	"ETAT_CIVIL_AGENT" VARCHAR2(20 BYTE), 
	"EMAIL_AGENT" VARCHAR2(20 BYTE), 
	"IMAGE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CELLULE
--------------------------------------------------------

  CREATE TABLE "NOUR"."CELLULE" 
   (	"ID_CELLULE" NUMBER(*,0), 
	"TYPE_CELLULE" VARCHAR2(20 BYTE), 
	"NB_LITS" NUMBER, 
	"SUPERFICIE_CELLULE" NUMBER, 
	"NB_DETENUS" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CITOYENS
--------------------------------------------------------

  CREATE TABLE "NOUR"."CITOYENS" 
   (	"CIN_CITOYEN" VARCHAR2(20 BYTE), 
	"NOM_CITOYEN" VARCHAR2(20 BYTE), 
	"PRENOM_CITOYEN" VARCHAR2(20 BYTE), 
	"SEXE_CITOYEN" VARCHAR2(20 BYTE), 
	"DATE_DE_NAISSANCE_CITOYEN" VARCHAR2(20 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"TELEPHONE" VARCHAR2(20 BYTE), 
	"NATIONNALITE_CITOYEN" VARCHAR2(20 BYTE), 
	"ETAT_CIVIL_CITOYEN" VARCHAR2(20 BYTE), 
	"EMAIL_CITOYEN" VARCHAR2(20 BYTE), 
	"IMAGE" BLOB
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" 
 LOB ("IMAGE") STORE AS (
  TABLESPACE "SYSTEM" ENABLE STORAGE IN ROW CHUNK 8192 PCTVERSION 10
  NOCACHE LOGGING 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)) ;
--------------------------------------------------------
--  DDL for Table DETENU
--------------------------------------------------------

  CREATE TABLE "NOUR"."DETENU" 
   (	"ID_DETENU" NUMBER, 
	"NOM_DETENU" VARCHAR2(20 BYTE), 
	"PRENOM_DETENU" VARCHAR2(20 BYTE), 
	"DATE_NAISSANCE_DETENU" NVARCHAR2(20), 
	"NATIONALITE_DETENU" VARCHAR2(20 BYTE), 
	"SEXE_DETENU" VARCHAR2(20 BYTE), 
	"TAILLE_DETENU" NUMBER, 
	"POIDS_DETENU" NUMBER, 
	"PERIODE_DETENU" VARCHAR2(20 BYTE), 
	"DOSSIER_DETENU" VARCHAR2(20 BYTE), 
	"ID_CELLULE" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EQUIPEMENT
--------------------------------------------------------

  CREATE TABLE "NOUR"."EQUIPEMENT" 
   (	"IDEQUIPEMENT" NUMBER, 
	"NOMEQUIPEMENT" VARCHAR2(20 BYTE), 
	"TYPEEQUIPEMENT" VARCHAR2(20 BYTE), 
	"QUANTITEEQUIPEMENT" NUMBER, 
	"ETATEQUIPEMENT" NUMBER, 
	"DATEFABRICATION" DATE
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MAINTENANCE
--------------------------------------------------------

  CREATE TABLE "NOUR"."MAINTENANCE" 
   (	"IDMAINTENANCE" NUMBER, 
	"DUREEMAINTENANCE" VARCHAR2(20 BYTE), 
	"DATEENTREEM" VARCHAR2(20 BYTE), 
	"DATESORTIEM" VARCHAR2(20 BYTE), 
	"FRAIS" NUMBER, 
	"FK_EQUIPEMENT" NUMBER
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MISSION
--------------------------------------------------------

  CREATE TABLE "NOUR"."MISSION" 
   (	"ID" VARCHAR2(20 BYTE), 
	"NBR_VEHICULE" NUMBER, 
	"NBR_POLICIER" NUMBER, 
	"DATE_MISSION" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PERSONNE
--------------------------------------------------------

  CREATE TABLE "NOUR"."PERSONNE" 
   (	"id" NUMBER, 
	"nom" VARCHAR2(20 BYTE), 
	"prenom" VARCHAR2(20 BYTE), 
	"adresse" VARCHAR2(30 BYTE), 
	"daten" VARCHAR2(30 BYTE), 
	"sexe" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PETITION
--------------------------------------------------------

  CREATE TABLE "NOUR"."PETITION" 
   (	"ID_PETITION" VARCHAR2(20 BYTE), 
	"TITRE_PETITION" VARCHAR2(40 BYTE), 
	"AUTEUR_PETITION" VARCHAR2(40 BYTE), 
	"DATE_PETITION" VARCHAR2(40 BYTE), 
	"DESCRIPTION_PETITION" VARCHAR2(1000 BYTE), 
	"VALIDITE_PETITION" VARCHAR2(20 BYTE), 
	"NBR_SIGNATURES_REQUIS" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PLAINTE
--------------------------------------------------------

  CREATE TABLE "NOUR"."PLAINTE" 
   (	"idp" NUMBER, 
	"raison" VARCHAR2(30 BYTE), 
	"datep" VARCHAR2(30 BYTE), 
	"type" VARCHAR2(30 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table SERVICE
--------------------------------------------------------

  CREATE TABLE "NOUR"."SERVICE" 
   (	"ID_SERVICE" VARCHAR2(20 BYTE), 
	"LIBELLE_SERVICE" VARCHAR2(20 BYTE), 
	"AGENT_SERVICE" VARCHAR2(20 BYTE), 
	"DATE_SERVICE" VARCHAR2(20 BYTE), 
	"DESCRIPTION_SERVICE" VARCHAR2(20 BYTE), 
	"GENRE_SERVICE" VARCHAR2(20 BYTE), 
	"NOM_DEPARTEMENT" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table STPSADMIN
--------------------------------------------------------

  CREATE TABLE "NOUR"."STPSADMIN" 
   (	"USERNAME" VARCHAR2(20 BYTE), 
	"PASSWORD" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table VEHICULE
--------------------------------------------------------

  CREATE TABLE "NOUR"."VEHICULE" 
   (	"ID" NUMBER, 
	"MARQUE" VARCHAR2(20 BYTE), 
	"MODEL" VARCHAR2(20 BYTE)
   ) PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into NOUR.AGENT
SET DEFINE OFF;
Insert into NOUR.AGENT (CIN_AGENT,NOM_AGENT,PRENOM_AGENT,SEXE_AGENT,DATE_DE_NAISSANCE_AGENT,ADRESSE_AGENT,TELEPHONE_AGENT,NATIONALITE_AGENT,ETAT_CIVIL_AGENT,EMAIL_AGENT,IMAGE) values ('55',null,null,'homme','01/01/2000',null,null,null,null,null,null);
Insert into NOUR.AGENT (CIN_AGENT,NOM_AGENT,PRENOM_AGENT,SEXE_AGENT,DATE_DE_NAISSANCE_AGENT,ADRESSE_AGENT,TELEPHONE_AGENT,NATIONALITE_AGENT,ETAT_CIVIL_AGENT,EMAIL_AGENT,IMAGE) values ('2',null,null,'homme','01/01/2000',null,null,null,null,null,null);
REM INSERTING into NOUR.CELLULE
SET DEFINE OFF;
Insert into NOUR.CELLULE (ID_CELLULE,TYPE_CELLULE,NB_LITS,SUPERFICIE_CELLULE,NB_DETENUS) values (1,'tyyy',500,100,10);
Insert into NOUR.CELLULE (ID_CELLULE,TYPE_CELLULE,NB_LITS,SUPERFICIE_CELLULE,NB_DETENUS) values (44,'tyyy',500,100,10);
REM INSERTING into NOUR.CITOYENS
SET DEFINE OFF;
REM INSERTING into NOUR.DETENU
SET DEFINE OFF;
Insert into NOUR.DETENU (ID_DETENU,NOM_DETENU,PRENOM_DETENU,DATE_NAISSANCE_DETENU,NATIONALITE_DETENU,SEXE_DETENU,TAILLE_DETENU,POIDS_DETENU,PERIODE_DETENU,DOSSIER_DETENU,ID_CELLULE) values (22,'nour','zrraibia',null,null,'femme',0,0,null,null,'1');
Insert into NOUR.DETENU (ID_DETENU,NOM_DETENU,PRENOM_DETENU,DATE_NAISSANCE_DETENU,NATIONALITE_DETENU,SEXE_DETENU,TAILLE_DETENU,POIDS_DETENU,PERIODE_DETENU,DOSSIER_DETENU,ID_CELLULE) values (11,'ahlem','zaghouani',null,null,'homme',0,0,null,null,'0');
Insert into NOUR.DETENU (ID_DETENU,NOM_DETENU,PRENOM_DETENU,DATE_NAISSANCE_DETENU,NATIONALITE_DETENU,SEXE_DETENU,TAILLE_DETENU,POIDS_DETENU,PERIODE_DETENU,DOSSIER_DETENU,ID_CELLULE) values (33,'az','zza',null,null,null,0,0,null,null,null);
Insert into NOUR.DETENU (ID_DETENU,NOM_DETENU,PRENOM_DETENU,DATE_NAISSANCE_DETENU,NATIONALITE_DETENU,SEXE_DETENU,TAILLE_DETENU,POIDS_DETENU,PERIODE_DETENU,DOSSIER_DETENU,ID_CELLULE) values (44,'jjj','kk',null,null,null,0,0,null,null,null);
Insert into NOUR.DETENU (ID_DETENU,NOM_DETENU,PRENOM_DETENU,DATE_NAISSANCE_DETENU,NATIONALITE_DETENU,SEXE_DETENU,TAILLE_DETENU,POIDS_DETENU,PERIODE_DETENU,DOSSIER_DETENU,ID_CELLULE) values (55,'hh',null,null,null,null,0,0,null,null,null);
Insert into NOUR.DETENU (ID_DETENU,NOM_DETENU,PRENOM_DETENU,DATE_NAISSANCE_DETENU,NATIONALITE_DETENU,SEXE_DETENU,TAILLE_DETENU,POIDS_DETENU,PERIODE_DETENU,DOSSIER_DETENU,ID_CELLULE) values (66,'aaa','z',null,null,null,0,0,null,null,null);
REM INSERTING into NOUR.EQUIPEMENT
SET DEFINE OFF;
Insert into NOUR.EQUIPEMENT (IDEQUIPEMENT,NOMEQUIPEMENT,TYPEEQUIPEMENT,QUANTITEEQUIPEMENT,ETATEQUIPEMENT,DATEFABRICATION) values (1,'nounou','type1',20,0,to_date('23-03-00','DD-MM-RR'));
Insert into NOUR.EQUIPEMENT (IDEQUIPEMENT,NOMEQUIPEMENT,TYPEEQUIPEMENT,QUANTITEEQUIPEMENT,ETATEQUIPEMENT,DATEFABRICATION) values (133,'piiii','tyyyy',2000,1,to_date('06-01-00','DD-MM-RR'));
Insert into NOUR.EQUIPEMENT (IDEQUIPEMENT,NOMEQUIPEMENT,TYPEEQUIPEMENT,QUANTITEEQUIPEMENT,ETATEQUIPEMENT,DATEFABRICATION) values (2,'gun','type5',35,0,null);
Insert into NOUR.EQUIPEMENT (IDEQUIPEMENT,NOMEQUIPEMENT,TYPEEQUIPEMENT,QUANTITEEQUIPEMENT,ETATEQUIPEMENT,DATEFABRICATION) values (12,'pistolet','type5',35,1,null);
Insert into NOUR.EQUIPEMENT (IDEQUIPEMENT,NOMEQUIPEMENT,TYPEEQUIPEMENT,QUANTITEEQUIPEMENT,ETATEQUIPEMENT,DATEFABRICATION) values (333,'nour','nour',20,0,to_date('26-03-00','DD-MM-RR'));
Insert into NOUR.EQUIPEMENT (IDEQUIPEMENT,NOMEQUIPEMENT,TYPEEQUIPEMENT,QUANTITEEQUIPEMENT,ETATEQUIPEMENT,DATEFABRICATION) values (222,'nour','type',20,0,to_date('26-03-00','DD-MM-RR'));
Insert into NOUR.EQUIPEMENT (IDEQUIPEMENT,NOMEQUIPEMENT,TYPEEQUIPEMENT,QUANTITEEQUIPEMENT,ETATEQUIPEMENT,DATEFABRICATION) values (1444,'11555','1555',1555,1,to_date('08-01-00','DD-MM-RR'));
REM INSERTING into NOUR.MAINTENANCE
SET DEFINE OFF;
Insert into NOUR.MAINTENANCE (IDMAINTENANCE,DUREEMAINTENANCE,DATEENTREEM,DATESORTIEM,FRAIS,FK_EQUIPEMENT) values (1,'60min','03/03/2019','03/03/2019',65,1);
REM INSERTING into NOUR.MISSION
SET DEFINE OFF;
REM INSERTING into NOUR.PERSONNE
SET DEFINE OFF;
REM INSERTING into NOUR.PETITION
SET DEFINE OFF;
REM INSERTING into NOUR.PLAINTE
SET DEFINE OFF;
REM INSERTING into NOUR.SERVICE
SET DEFINE OFF;
Insert into NOUR.SERVICE (ID_SERVICE,LIBELLE_SERVICE,AGENT_SERVICE,DATE_SERVICE,DESCRIPTION_SERVICE,GENRE_SERVICE,NOM_DEPARTEMENT) values ('33','y','t','01/01/2000',null,'demande cin',null);
Insert into NOUR.SERVICE (ID_SERVICE,LIBELLE_SERVICE,AGENT_SERVICE,DATE_SERVICE,DESCRIPTION_SERVICE,GENRE_SERVICE,NOM_DEPARTEMENT) values ('8585','ss','ss','01/01/2000','ss','demande cin','ss');
REM INSERTING into NOUR.STPSADMIN
SET DEFINE OFF;
Insert into NOUR.STPSADMIN (USERNAME,PASSWORD) values ('test','test');
REM INSERTING into NOUR.VEHICULE
SET DEFINE OFF;
--------------------------------------------------------
--  DDL for Index SERVICE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "NOUR"."SERVICE_PK" ON "NOUR"."SERVICE" ("ID_SERVICE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index MISSION_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "NOUR"."MISSION_PK" ON "NOUR"."MISSION" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PLAINTE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "NOUR"."PLAINTE_PK" ON "NOUR"."PLAINTE" ("idp") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CITOYENS_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "NOUR"."CITOYENS_PK" ON "NOUR"."CITOYENS" ("CIN_CITOYEN") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index AGENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "NOUR"."AGENT_PK" ON "NOUR"."AGENT" ("CIN_AGENT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PERSONNE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "NOUR"."PERSONNE_PK" ON "NOUR"."PERSONNE" ("id") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index MAINTENANCE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "NOUR"."MAINTENANCE_PK" ON "NOUR"."MAINTENANCE" ("IDMAINTENANCE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index VEHICULE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "NOUR"."VEHICULE_PK" ON "NOUR"."VEHICULE" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EQUIPEMENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "NOUR"."EQUIPEMENT_PK" ON "NOUR"."EQUIPEMENT" ("IDEQUIPEMENT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CELLULE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "NOUR"."CELLULE_PK" ON "NOUR"."CELLULE" ("ID_CELLULE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index DETENU_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "NOUR"."DETENU_PK" ON "NOUR"."DETENU" ("ID_DETENU") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table MAINTENANCE
--------------------------------------------------------

  ALTER TABLE "NOUR"."MAINTENANCE" ADD CONSTRAINT "MAINTENANCE_PK" PRIMARY KEY ("IDMAINTENANCE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "NOUR"."MAINTENANCE" MODIFY ("IDMAINTENANCE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table SERVICE
--------------------------------------------------------

  ALTER TABLE "NOUR"."SERVICE" MODIFY ("ID_SERVICE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PLAINTE
--------------------------------------------------------

  ALTER TABLE "NOUR"."PLAINTE" MODIFY ("idp" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MISSION
--------------------------------------------------------

  ALTER TABLE "NOUR"."MISSION" ADD CONSTRAINT "MISSION_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "NOUR"."MISSION" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CITOYENS
--------------------------------------------------------

  ALTER TABLE "NOUR"."CITOYENS" ADD CONSTRAINT "CITOYENS_PK" PRIMARY KEY ("CIN_CITOYEN")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "NOUR"."CITOYENS" MODIFY ("CIN_CITOYEN" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EQUIPEMENT
--------------------------------------------------------

  ALTER TABLE "NOUR"."EQUIPEMENT" ADD CONSTRAINT "EQUIPEMENT_PK" PRIMARY KEY ("IDEQUIPEMENT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "NOUR"."EQUIPEMENT" MODIFY ("IDEQUIPEMENT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table AGENT
--------------------------------------------------------

  ALTER TABLE "NOUR"."AGENT" ADD CONSTRAINT "AGENT_PK" PRIMARY KEY ("CIN_AGENT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "NOUR"."AGENT" MODIFY ("CIN_AGENT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CELLULE
--------------------------------------------------------

  ALTER TABLE "NOUR"."CELLULE" ADD CONSTRAINT "CELLULE_PK" PRIMARY KEY ("ID_CELLULE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "NOUR"."CELLULE" MODIFY ("ID_CELLULE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PETITION
--------------------------------------------------------

  ALTER TABLE "NOUR"."PETITION" MODIFY ("ID_PETITION" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table DETENU
--------------------------------------------------------

  ALTER TABLE "NOUR"."DETENU" ADD CONSTRAINT "DETENUU_PK" PRIMARY KEY ("ID_DETENU")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "NOUR"."DETENU" MODIFY ("ID_DETENU" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table VEHICULE
--------------------------------------------------------

  ALTER TABLE "NOUR"."VEHICULE" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PERSONNE
--------------------------------------------------------

  ALTER TABLE "NOUR"."PERSONNE" ADD CONSTRAINT "PERSONNE_PK" PRIMARY KEY ("id")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
 
  ALTER TABLE "NOUR"."PERSONNE" MODIFY ("id" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table MAINTENANCE
--------------------------------------------------------

  ALTER TABLE "NOUR"."MAINTENANCE" ADD CONSTRAINT "MAINTENANCE_FK1" FOREIGN KEY ("FK_EQUIPEMENT")
	  REFERENCES "NOUR"."EQUIPEMENT" ("IDEQUIPEMENT") ENABLE;
