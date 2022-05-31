all:
	platformio -c qtcreator run

deploy:
	platformio run --target upload
	
monitor:
	platformio device monitor
	#xterm -hold -e platformio device monitor
	#xterm -e platformio device monitor
	#MONITOR="$(platformio device monitor)"
	#bash $MONITOR

# regenerate project files to reflect platformio.ini changes
project-update:
	@echo "This will overwrite project metadata files.  Are you sure? [y/N] " \
	    && read ans && [ $${ans:-'N'} = 'y' ]
	platformio project init --ide qtcreator

# forward any other target (clean, build, etc.) to pio run
%:
	platformio -c qtcreator run --target $*
