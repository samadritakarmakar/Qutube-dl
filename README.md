# This is a free youtube video downloader. It is a Qt based GUI frontend for youtube-dl. (See https://github.com/rg3/youtube-dl)

# HOW TO COMPILE.

unpack the file in your preferred location

type the following:

    cd Qutube-dl

    qmake Qutube-dl.pro

    make

you may also use QtCreator to compile.

SETUP AFTER COMPILATION

Create a folder 'Qutube-dl'
Move the executable (.exe for windows users) file just compiled into the folder.

Windows users add the bin directory of your Qt installation (e.g. <QT_DIR\bin>) to the PATH variable and then run:

    windeployqt 'path to Qutube-dl executable' 

Create a new folder 'youtube-dl' within 'Qutube-dl' folder
download the latest version of youtube-dl from https://rg3.github.io/youtube-dl/ and place within 'youtube-dl' folder.

Windows users must download the 'Windows executable that includes Python.'
Linux users must download python version by typing

    wget https://yt-dl.org/downloads/latest/youtube-dl

# HOW TO USE

copy and paste the video url in the box labelled 'Url'

You may directly press button 'Go!' to download the video to your desired location.
![alt tag](https://github.com/samadritakarmakar/Qutube-dl/blob/master/Screeshot_download.png)

You may check the available versions by clicking 'Available Format?' button.  
Look for numbers under 'format code' in the output if you click the 'Available Format?' button.Enter the desired format code in 'Format code' box and press 'Go!'  

![alt tag](https://github.com/samadritakarmakar/Qutube-dl/blob/master/Screenshot_format_code_1.png)
![alt tag](https://github.com/samadritakarmakar/Qutube-dl/blob/master/Screenshot_format_code_2.png)
![alt tag](https://github.com/samadritakarmakar/Qutube-dl/blob/master/Screenshot_update_backend.png)

Thanks for using Qutube-dl!  

