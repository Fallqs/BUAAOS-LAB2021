get:
	touch getScore
	git add .
	git commit -m "auto score"
	git push
	rm getScore

push:
	git add .
	git commit -m "auto"
	git push


