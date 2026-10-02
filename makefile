outfile:main.o inputfun.o addbook.o updatebook.o updatebyid.o updatebyname.o removebook.o removebyit.o removebyname.o searchbook.o searchbyid.o searchbyname.o searchbyauthor.o viewallbooks.o issuebook.o returnbook.o listissuedbook.o savedata.o loaddata.o bookexits.o findbookbyid.o updatebookquantity.o printbook.o casesensitivesearch.o currentdate.o duedate.o datetotime.o callatedays.o nextissueid.o
	cc main.c inputfun.c addbook.c updatebook.c updatebyid.c updatebyname.c removebook.c removebyit.c removebyname.c searchbook.c searchbyid.c searchbyname.c searchbyauthor.c viewallbooks.c issuebook.c returnbook.c listissuedbook.c savedata.c loaddata.c bookexits.c findbookbyid.c updatebookquantity.c printbook.c casesensitivesearch.c currentdate.c duedate.c datetotime.c callatedays.c nextissueid.c
main.o:main.c
	cc -c main.c
inputfun.o:inputfun.c
	cc -c inputfun.c
addbook.o:addbook.c
	cc -c addbook.c
updatebook.o:updatebook.c
	cc -c updatebook.c
updatebyid.o:updatebyid.c
	cc -c updatebyid.c
updatebyname.o:updatebyname.c
	cc -c updatebyname.c
removebook.o:removebook.c
	cc -c removebook.c
removebyit.o:removebyit.c
	cc -c removebyit.c
removebyname.o:removebyname.c
	cc -c removebyname.c
searchbook.o:searchbook.c
	cc -c searchbook.c
searchbyid.o:searchbyid.c
	cc -c searchbyid.c
searchbyname.o:searchbyname.c
	cc -c searchbyname.c
searchbyauthor.o:searchbyauthor.c
	cc -c searchbyauthor.c
viewallbooks.o:viewallbooks.c
	cc -c viewallbooks.c
issuebook.o:issuebook.c
	cc -c issuebook.c
returnbook.o:returnbook.c
	cc -c returnbook.c
listissuedbook.o:listissuedbook.c
	cc -c listissuedbook.c
savedata.o:savedata.c
	cc -c savedata.c
loaddata.o:loaddata.c
	cc -c loaddata.c
bookexits.o:bookexits.c
	cc -c bookexits.c
findbookbyid.o:findbookbyid.c
	cc -c findbookbyid.c
updatebookquantity.o:updatebookquantity.c
	cc -c updatebookquantity.c
printbook.o:printbook.c
	cc -c printbook.c
casesensitivesearch.o:casesensitivesearch.c
	cc -c casesensitivesearch.c
currentdate.o:currentdate.c
	cc -c currentdate.c
duedate.o:duedate.c
	cc -c duedate.c
datetotime.o:datetotime.c
	cc -c datetotime.c
callatedays.o:callatedays.c
	cc -c callatedays.c
nextissueid.o:nextissueid.c
	cc -c nextissueid.c
