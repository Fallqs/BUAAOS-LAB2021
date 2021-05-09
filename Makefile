get:
	touch getScore
	git add .
	git commit --allow-empty -m "auto score"
	git push origin racing-2021:racing-2021
	rm getScore
	git rm --cached getScore

push:
	git add .
	git commit --allow-empty -m "auto"
	git push origin racing-2021:racing-2021


