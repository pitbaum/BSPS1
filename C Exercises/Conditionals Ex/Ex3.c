int day;
int month;
int year;
int nextday;
int nextmonth;
int nextyear;

main(){
	scanf("%d", &day);
	scanf("%d", &month);
	scanf("%d", &year);
	nextyear = year;
	nextmonth = month;
	nextday = day;
	if(month == 1 && day == 31 || month == 3 && day == 31 || month == 5 && day == 31 || month == 7 && day == 31 || month == 8 && day == 31 || month == 10 && day == 31){
		nextmonth = month +1;
		nextday = 1;
	}
	else if(month == 4 && day == 30 || month == 6 && day == 30 || month == 9 && day == 30 || month == 11 && day == 30){
		nextmonth = month +1;
		nextday = 1;
	}
	else if(month == 2 && day == 29){
		nextmonth = month +1;
		nextday = 1;
	}
	else if(month == 12 && day == 31){
		nextmonth = 1;
		nextday = 1;
		nextyear = year + 1;
	}
	else{
		nextday = day + 1;
	}
	
	printf("Date following %d : %d : %d is %d : %d : %d \n", day, month, year, nextday, nextmonth, nextyear);
}
