get:
	touch getScore
	git add .
	time=$(date "+%Y-%m-%d %H:%M:%S")
	git commit --allow-empty -m "${time}"
	git push origin racing-2021:racing-2021
	rm getScore
	git rm --cached getScore

push:
	git add .
	time=$(date "+%Y-%m-%d %H:%M:%S")
	git commit --allow-empty -m "auto ${time}"
	git push origin racing-2021:racing-2021


