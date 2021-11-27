# 데이터베이스 기초 필기

## Week 3

### MySQL

- 처리속도가 상당히 빠르고 대용량 데이터 처리용이
- 설치 방법이 쉽고 익히기 쉬움
- 보안성 우수
- 무료

```sakila 설치
cd ~/Downloads
wget http://downloads.mysql.com/docs/sakila-db.tar.gz
tar -xzf sakila-db.tar.gz
cd sakila-db
mysql -u root -p < sakila-schema.sql
mysql -u root -p < sakila-data.sql
```


```데이터 베이스 권한 부여
GRANT ALL PRIVILEGES ON *.* TO 'san'@'localhost';
```

### defualt database 설정

- 설정전
  - select * from my_db.emp;
- 설정후
  - select * from emp;