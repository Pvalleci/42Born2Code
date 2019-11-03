if [ $# != 4 ]
then
	echo "usage : script <lien github> <depot> <objet a git> <commit>"
else
	git clone $1 $2
	cp -r $3 $2
	cd $2 ; git add $3 ; git status ; git commit -m "$4" ; git push origin master ; rm -rf $2
fi
