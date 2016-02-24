BEGIN TRANSACTION;


---------------------------------ϵͳ�û������ϵ��--------------------------------------------------------------------
CREATE TABLE Tbl_user --�û���
 (
  user_id numeric(6) PRIMARY KEY,--�û����
  user_name varchar(15) not null,--�û���
  user_pwd varchar(10),          --�û�����
  user_account varchar(15),      --�û��ʺ�
  user_stat integer default 1,   --�û�״̬
  user_remark text               --��ע
  );
  
INSERT INTO "Tbl_user" VALUES(1,'admin','123456','100000',1,'����Ա');
INSERT INTO "Tbl_user" VALUES(2,'mick','000000','100001',1,'');
INSERT INTO "Tbl_user" VALUES(3,'tom','888888','100002',1,'');
INSERT INTO "Tbl_user" VALUES(4,'jujy','123456','100003',1,'');
INSERT INTO "Tbl_user" VALUES(5,'jack','123456','100004',1,'');
INSERT INTO "Tbl_user" VALUES(6,'test1','0','100005',1,'NULL');
INSERT INTO "Tbl_user" VALUES(7,'test2','0','100006',1,'NULL');
INSERT INTO "Tbl_user" VALUES(8,'test3','0','100007',1,'NULL');
INSERT INTO "Tbl_user" VALUES(9,'test4','0','100008',1,'NULL');
INSERT INTO "Tbl_user" VALUES(10,'test5','0','100009',1,'NULL');
INSERT INTO "Tbl_user" VALUES(11,'test8','0','100010',1,'NULL');
INSERT INTO "Tbl_user" VALUES(12,'test9','0','100011',1,'NULL');
INSERT INTO "Tbl_user" VALUES(13,'test6','0','100012',1,'');
INSERT INTO "Tbl_user" VALUES(14,'test7','0','100013',1,'test');
INSERT INTO "Tbl_user" VALUES(15,'����','0','100014',1,'����');
INSERT INTO "Tbl_user" VALUES(16,'���','0','100015',1,'����');
INSERT INTO "Tbl_user" VALUES(17,'����','0','100016',1,'����');
INSERT INTO "Tbl_user" VALUES(18,'³��','0','100017',1,'�Ӿ�');
INSERT INTO "Tbl_user" VALUES(19,'��ͳ','0','100018',1,'ʿԪ');
INSERT INTO "Tbl_user" VALUES(20,'ˮ������','0','100019',1,'δ��');
INSERT INTO "Tbl_user" VALUES(21,'����','0','100020',1,'����');
INSERT INTO "Tbl_user" VALUES(22,'����','0','100021',1,'��Т');
CREATE TABLE Tbl_role --��ɫ��
 (
   role_id numeric(6) PRIMARY KEY,
   role_name varchar(30)
 );
 
INSERT INTO "Tbl_role" VALUES(1000,'����Ա');
INSERT INTO "Tbl_role" VALUES(1001,'ҵ��Ա');
INSERT INTO "Tbl_role" VALUES(1002,'����Ա');
CREATE TABLE Tbl_user_role--�û���ɫ��ϵ��
 (
   user_id numeric(6) NOT NULL,
   role_id numeric(6) NOT NULL
 );
INSERT INTO "Tbl_user_role" VALUES(1,1000);
INSERT INTO "Tbl_user_role" VALUES(2,1001);
INSERT INTO "Tbl_user_role" VALUES(3,1002);
INSERT INTO "Tbl_user_role" VALUES(4,1001);
INSERT INTO "Tbl_user_role" VALUES(5,1000);
INSERT INTO "Tbl_user_role" VALUES(6,1002);
INSERT INTO "Tbl_user_role" VALUES(7,1002);
INSERT INTO "Tbl_user_role" VALUES(8,1002);
INSERT INTO "Tbl_user_role" VALUES(9,1002);
INSERT INTO "Tbl_user_role" VALUES(10,1002);
INSERT INTO "Tbl_user_role" VALUES(11,1002);
INSERT INTO "Tbl_user_role" VALUES(12,1002);
INSERT INTO "Tbl_user_role" VALUES(13,1002);
INSERT INTO "Tbl_user_role" VALUES(14,1002);
INSERT INTO "Tbl_user_role" VALUES(15,1002);
INSERT INTO "Tbl_user_role" VALUES(16,1002);
INSERT INTO "Tbl_user_role" VALUES(17,1002);
INSERT INTO "Tbl_user_role" VALUES(18,1001);
INSERT INTO "Tbl_user_role" VALUES(19,1001);
INSERT INTO "Tbl_user_role" VALUES(20,1001);
INSERT INTO "Tbl_user_role" VALUES(21,1001);
INSERT INTO "Tbl_user_role" VALUES(22,1001);


CREATE TABLE Tbl_role_menu--��ɫ�˵���ϵ��
 (
   role_id numeric(6) NOT NULL,
   menu_id numeric(6) NOT NULL
 );
INSERT INTO "Tbl_role_menu" VALUES(1000,2000);
INSERT INTO "Tbl_role_menu" VALUES(1000,2001);
INSERT INTO "Tbl_role_menu" VALUES(1000,2002);
INSERT INTO "Tbl_role_menu" VALUES(1000,2003);
INSERT INTO "Tbl_role_menu" VALUES(1000,2004);
INSERT INTO "Tbl_role_menu" VALUES(1001,2001);
INSERT INTO "Tbl_role_menu" VALUES(1001,2002);
INSERT INTO "Tbl_role_menu" VALUES(1001,2003);
INSERT INTO "Tbl_role_menu" VALUES(1001,2004);
INSERT INTO "Tbl_role_menu" VALUES(1002,2003);
INSERT INTO "Tbl_role_menu" VALUES(1002,2004);
CREATE TABLE Tbl_menu--�˵���
 (
   menu_id numeric(6) PRIMARY KEY,
   menu_name VARCHAR(30) NOT NULL,
   menu_fid numeric(6)
 );
 
INSERT INTO "Tbl_menu" VALUES(2000,'ϵͳ����',0);
INSERT INTO "Tbl_menu" VALUES(2001,'�ͻ��˹���',0);
INSERT INTO "Tbl_menu" VALUES(2002,'��Ƶ����',0);
INSERT INTO "Tbl_menu" VALUES(2003,'����ͳ��',0);
INSERT INTO "Tbl_menu" VALUES(2004,'�˳���¼',0);
INSERT INTO "Tbl_menu" VALUES(2010,'��֯��������',2000);
INSERT INTO "Tbl_menu" VALUES(2011,'�û�����',2000);
INSERT INTO "Tbl_menu" VALUES(2012,'ϵͳ��������',2000);
INSERT INTO "Tbl_menu" VALUES(2013,'�û�����',2001);
INSERT INTO "Tbl_menu" VALUES(2014,'�û��㲥����',2001);
INSERT INTO "Tbl_menu" VALUES(2015,'Ƶ����Ϣ����',2002);
INSERT INTO "Tbl_menu" VALUES(2016,'������Ϣ����',2002);
INSERT INTO "Tbl_menu" VALUES(2017,'������Ϣ����',2002);
INSERT INTO "Tbl_menu" VALUES(2018,'��Ƶ��Ϣ����',2002);
INSERT INTO "Tbl_menu" VALUES(2019,'�㲥����',2003);
INSERT INTO "Tbl_menu" VALUES(2020,'ע��',2004);
INSERT INTO "Tbl_menu" VALUES(2021,'�˳�',2004);
------------------------------------�ͻ����û������--------------------------------------------------------------------
CREATE TABLE Tbl_cuser   --�ͻ����û���
 (
   user_id numeric(6) PRIMARY KEY,
   user_name VARCHAR(30) NOT NULL,
   user_pwd varchar(10),
   user_account varchar(15),  --�û��ʺ�
   user_stat integer,
   user_logintime TEXT,
   user_remark TEXT
 );
INSERT INTO "Tbl_cuser" VALUES(1,'songjiang','a',"100000",1,'2013-09-01','student');
INSERT INTO "Tbl_cuser" VALUES(2,'mick','000000',"100001",1,'2013-04-04','NULL');
INSERT INTO "Tbl_cuser" VALUES(3,'tom','888888',"100002",1,'2013-05-10','student');
INSERT INTO "Tbl_cuser" VALUES(4,'taiseng','123456',"100003",1,'2013-09-17','teacher');
INSERT INTO "Tbl_cuser" VALUES(5,'xiaosi','888888',"100004",1,'2013-08-12','student');
INSERT INTO "Tbl_cuser" VALUES(6,'xiaowu','123456',"100005",1,'2012-12-12','poet');
INSERT INTO "Tbl_cuser" VALUES(7,'xiaoxi','888888','100006',1,'2013-07-13','drewer');
INSERT INTO "Tbl_cuser" VALUES(8,'xiaoming','123456','100007',1,'2013-01-12','singer');


--------------------------------------����ͳ�ƹ�ϵ��--------------------------------------------------------------------
 CREATE TABLE Tbl_video_message  --��Ƶ��Ϣ��
(
  video_id numeric(6) PRIMARY KEY,--��ƵID
  channel_id numeric(6),--Ƶ��ID
  area_id numeric(6),--����ID
  type_id numeric(6),--����ID
  video_name text--��Ƶ����
  --play_count integer--���Ŵ���
 );
 INSERT INTO "Tbl_video_message" VALUES(1000,2,1,4,'Ӣ��');
 INSERT INTO "Tbl_video_message" VALUES(1001,2,2,3,'�����ߺ�');
 INSERT INTO "Tbl_video_message" VALUES(1002,2,4,1,'ָ����');
 INSERT INTO "Tbl_video_message" VALUES(1003,1,1,5,'�������');
 INSERT INTO "Tbl_video_message" VALUES(1004,3,1,6,'��������');
 INSERT INTO "Tbl_video_message" VALUES(1005,2,3,3,'��������');
 INSERT INTO "Tbl_video_message" VALUES(1006,2,4,3,'��Ȯ�˹�');
 INSERT INTO "Tbl_video_message" VALUES(1007,2,1,3,'��ɽ�����');
 INSERT INTO "Tbl_video_message" VALUES(1008,2,2,3,'��̨');
 INSERT INTO "Tbl_video_message" VALUES(1009,1,1,5,'��������');
 INSERT INTO "Tbl_video_message" VALUES(1010,2,1,2,'���ŷɼ�');
 INSERT INTO "Tbl_video_message" VALUES(1011,2,4,1,'֩����');
 INSERT INTO "Tbl_video_message" VALUES(1012,2,4,1,'���ν��');
 INSERT INTO "Tbl_video_message" VALUES(1013,3,1,6,'�й�������');
 INSERT INTO "Tbl_video_message" VALUES(1014,2,2,3,'������͵');
 INSERT INTO "Tbl_video_message" VALUES(1015,4,3,7,'����');
 INSERT INTO "Tbl_video_message" VALUES(1016,4,3,7,'����');
 INSERT INTO "Tbl_video_message" VALUES(1017,4,3,7,'����');
 INSERT INTO "Tbl_video_message" VALUES(1018,4,3,7,'˭��������');
 INSERT INTO "Tbl_video_message" VALUES(1019,3,4,6,'������');
 INSERT INTO "Tbl_video_message" VALUES(1020,3,2,6,'��������');
 INSERT INTO "Tbl_video_message" VALUES(1021,1,2,5,'������');
 INSERT INTO "Tbl_video_message" VALUES(1022,1,3,5,'�Ĵ����');
 INSERT INTO "Tbl_video_message" VALUES(1023,1,1,4,'С��ɵ�');
 INSERT INTO "Tbl_video_message" VALUES(1024,1,1,4,'�������µ�');


 CREATE TABLE Tbl_video_area  --��Ƶ������Ϣ��
(
  area_id varchar(6) PRIMARY KEY,--����ID
  area_name text--��������
 );
 INSERT INTO "Tbl_video_area" VALUES('','ȫ��');
 INSERT INTO "Tbl_video_area" VALUES('1','��½');
 INSERT INTO "Tbl_video_area" VALUES('2','̨��');
 INSERT INTO "Tbl_video_area" VALUES('3','���');
 INSERT INTO "Tbl_video_area" VALUES('4','����');
 
 CREATE TABLE Tbl_video_channel  --��ƵƵ����Ϣ��
(
  channel_id varchar(6) PRIMARY KEY,--Ƶ��ID
  channel_name text--Ƶ������
 );
 INSERT INTO "Tbl_video_channel" VALUES('','ȫ��');
 INSERT INTO "Tbl_video_channel" VALUES('1','���Ӿ�');
 INSERT INTO "Tbl_video_channel" VALUES('2','��Ӱ');
 INSERT INTO "Tbl_video_channel" VALUES('3','����');
 INSERT INTO "Tbl_video_channel" VALUES('4','����');
 
 CREATE TABLE Tbl_video_type  --��Ƶ������Ϣ��
(
  type_id varchar(6) PRIMARY KEY,--����ID
  type_name text--��������
 );
 INSERT INTO "Tbl_video_type" VALUES('','ȫ��');
 INSERT INTO "Tbl_video_type" VALUES('1','ս��');
 INSERT INTO "Tbl_video_type" VALUES('2','����');
 INSERT INTO "Tbl_video_type" VALUES('3','����');
 INSERT INTO "Tbl_video_type" VALUES('4','����');
 INSERT INTO "Tbl_video_type" VALUES('5','��װ');
 INSERT INTO "Tbl_video_type" VALUES('6','ѡ��');
 INSERT INTO "Tbl_video_type" VALUES('7','MV');
 
 CREATE TABLE Tbl_video_details
 (
    video_id numeric(6),--��ƵID
    play_time text,
	play_count integer
  );
  INSERT INTO "Tbl_video_details" VALUES(1012,'2013-09-28',10);
  INSERT INTO "Tbl_video_details" VALUES(1012,'2013-09-28',14);
  INSERT INTO "Tbl_video_details" VALUES(1000,'2013-09-27',17);
  INSERT INTO "Tbl_video_details" VALUES(1000,'2013-09-28',13);
  INSERT INTO "Tbl_video_details" VALUES(1002,'2013-09-25',22);
  INSERT INTO "Tbl_video_details" VALUES(1002,'2013-09-25',19);
  INSERT INTO "Tbl_video_details" VALUES(1001,'2013-09-26',18);
  INSERT INTO "Tbl_video_details" VALUES(1001,'2013-09-28',17);
  INSERT INTO "Tbl_video_details" VALUES(1001,'2013-09-27',16);
  INSERT INTO "Tbl_video_details" VALUES(1003,'2013-09-28',14);
  INSERT INTO "Tbl_video_details" VALUES(1003,'2013-09-22',13);
  INSERT INTO "Tbl_video_details" VALUES(1004,'2013-09-27',15);
  INSERT INTO "Tbl_video_details" VALUES(1004,'2013-09-25',19);
  INSERT INTO "Tbl_video_details" VALUES(1005,'2013-09-27',16);
  INSERT INTO "Tbl_video_details" VALUES(1005,'2013-09-28',10);
  INSERT INTO "Tbl_video_details" VALUES(1006,'2013-09-26',21);
  INSERT INTO "Tbl_video_details" VALUES(1006,'2013-09-25',12);
  INSERT INTO "Tbl_video_details" VALUES(1007,'2013-09-28',13);
  INSERT INTO "Tbl_video_details" VALUES(1007,'2013-09-27',11);
  INSERT INTO "Tbl_video_details" VALUES(1008,'2013-09-25',12);
  INSERT INTO "Tbl_video_details" VALUES(1008,'2013-09-22',11);
  INSERT INTO "Tbl_video_details" VALUES(1008,'2013-09-28',13);
  INSERT INTO "Tbl_video_details" VALUES(1008,'2013-09-28',12);
  INSERT INTO "Tbl_video_details" VALUES(1009,'2013-09-22',17);
  INSERT INTO "Tbl_video_details" VALUES(1009,'2013-09-27',16);
  INSERT INTO "Tbl_video_details" VALUES(1018,'2013-09-27',15);
  INSERT INTO "Tbl_video_details" VALUES(1018,'2013-09-27',12);
  INSERT INTO "Tbl_video_details" VALUES(1018,'2013-09-27',13);
  INSERT INTO "Tbl_video_details" VALUES(1018,'2013-09-27',11);
  INSERT INTO "Tbl_video_details" VALUES(1015,'2013-09-28',11);
  INSERT INTO "Tbl_video_details" VALUES(1015,'2013-09-28',17);
  INSERT INTO "Tbl_video_details" VALUES(1015,'2013-09-28',18);
  INSERT INTO "Tbl_video_details" VALUES(1016,'2013-09-28',19);
  INSERT INTO "Tbl_video_details" VALUES(1016,'2013-09-28',16);
  INSERT INTO "Tbl_video_details" VALUES(1016,'2013-09-28',18);
  INSERT INTO "Tbl_video_details" VALUES(1013,'2013-09-01',17);
  INSERT INTO "Tbl_video_details" VALUES(1013,'2013-09-02',16);
  INSERT INTO "Tbl_video_details" VALUES(1013,'2013-09-24',15);
  INSERT INTO "Tbl_video_details" VALUES(1013,'2013-09-11',10);
  INSERT INTO "Tbl_video_details" VALUES(1013,'2013-09-23',12);
  INSERT INTO "Tbl_video_details" VALUES(1013,'2013-09-23',10);
  INSERT INTO "Tbl_video_details" VALUES(1022,'2013-09-29',21);
  INSERT INTO "Tbl_video_details" VALUES(1022,'2013-09-28',33);
  INSERT INTO "Tbl_video_details" VALUES(1011,'2013-09-23',22);
  INSERT INTO "Tbl_video_details" VALUES(1011,'2013-09-27',11);
  INSERT INTO "Tbl_video_details" VALUES(1011,'2013-09-29',23);
  INSERT INTO "Tbl_video_details" VALUES(1019,'2013-09-21',30);
  INSERT INTO "Tbl_video_details" VALUES(1010,'2013-09-22',21);
  INSERT INTO "Tbl_video_details" VALUES(1010,'2013-09-30',1);
  INSERT INTO "Tbl_video_details" VALUES(1024,'2013-09-28',23);
  INSERT INTO "Tbl_video_details" VALUES(1023,'2013-09-05',41);
  INSERT INTO "Tbl_video_details" VALUES(1024,'2013-09-22',21);
  INSERT INTO "Tbl_video_details" VALUES(1023,'2013-09-30',12);



 CREATE TABLE Tbl_video_menu  --��Ƶͳ���ֶ�
(
  menu_id varchar(6) PRIMARY KEY,--ͳ��ID
  menu_name text	--ͳ������
 );
 INSERT INTO "Tbl_video_menu" VALUES('','ȫ��');
 INSERT INTO "Tbl_video_menu" VALUES('1001','���ղ������');
 INSERT INTO "Tbl_video_menu" VALUES('1002','���ܲ������');
 INSERT INTO "Tbl_video_menu" VALUES('1003','���²������');
COMMIT;
