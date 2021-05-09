get:
	touch getScore
	git add .
	git commit -m "auto score"
	git push
	rm getScore
	git rm --cached getScore

push:
	git add .
	git commit --allow-empty -m "auto"
	git push


