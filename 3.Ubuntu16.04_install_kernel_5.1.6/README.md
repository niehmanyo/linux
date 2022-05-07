# Install Linux Kernel 5.1.6 in Ubuntu 16.04
<p><b>⚠️Warming</b>: If the Ubuntu version is 20.04, then it would be a failure in installation</p>
<p>❤Thanks to this <a href="https://www.cyberciti.biz/tips/compiling-linux-kernel-26.html">How to compile and install Linux Kernel 5.16.9 from source code</a> </p>


|Ubuntu|Kernel|Course|Group|
|-------|-----|-----|-----|
|16.04|5.1.6|CST308 Operating System|<p>Nie Wenyu</p><p>Zhu Qijin</p><p>Chen Nuo</p><p>Zhang Wei</p><p>Yao Lan</p>|

### Installation
<p>Using this command to check the version of your ubuntu</p>

```bash
uname -r  ##check the version
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.1.6.tar.xz ## Get the tar.xz file,my version is 5.1.64
																	 ## Or you can download this file in the website,I put it in my /home.
unxz -v linux-5.1.6.tar.xz ## To extract the source code.
```
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/1.png"> </p>


```bash 
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.1.6.tar.sign ## Download this file,then get the PGP signature
gpg --verify linux-5.1.6.tar.sign ## To get the key
gpg --recv-keys "your key-ID"	## Enter the key you receive, usually there is no problem
gpg --verify linux-5.1.6.tar.sign ## Verify it again							  
```

<p>Here are problems: </p>

* keyserver_receive failed: bad URI
* 

[Problems](#Keyserver and key)


<p>I noticed that the key is 6092693E,but when I enter</p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/2.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/3.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/4.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/5.png"> </p>

<p>Successful sample output:</p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/6.png"> </p>

<p>Now,we get the "linux-5.1.6.tar" file. Then untar this tarball.</p>

```bash
tar xvf linux-5.1.6.tar

```
<p>Here we get this dic "linux-5.1.6"</p>
<p>Before start building the kernel,one must configure Linux kernel features.Then copy existing config file from your /boot</p>

<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/7.png"> </p>

```bash
cp -v /boot/config-$(uname -r) .config ##copy the your configuration file to this linux dic

##my sample output
'/boot/config-4.15.0-112-generic'  ->  '.config'

```

<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/8.png"> </p>


```bash
sudo vim .config  ## to see the .config file (optional)
sudo apt-get install build-essential libncurses-dev bison flex libssl-dev libelf-dev
## this package help to compile kernel
```
<p><a href="https://www.cyberciti.biz/tips/linux-debian-package-management-cheat-sheet.html?utm_source=Linux_Unix_Command&utm_medium=tips&utm_campaign=nixcmd">For more information about "apt-get" command </a></p>


<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/9.png"></p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/10.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/11.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/12.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/13.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/14.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/15.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/16.png"> </p>


### Problems 