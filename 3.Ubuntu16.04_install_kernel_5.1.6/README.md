<p align="center">
<img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/linux_img.png">
</p>

# Install Linux Kernel 5.1.6 in Ubuntu 16.04

<p><b>⚠️Warming</b>: If the Ubuntu version is latest(s.t Ubuntu 20.04), then it would be a failure in installation</p>
<p>❤Thanks to this <a href="https://www.cyberciti.biz/tips/compiling-linux-kernel-26.html">How to compile and install Linux Kernel 5.16.9 from source code</a> </p>


|Ubuntu|Kernel|Course|Group|
|-------|-----|-----|-----|
|16.04|5.1.6|CST306 Operating System|<p>Nie Wenyu CST1909148</p><p>Zhu Qijin CST1909173</p><p>Chen Nuo CST1909128</p><p>Zhang Wei CST1909168</p><p>Yao Lan CST1909161</p>|

* Installation
* Problems
* Further Reading


# 1. Installation

<h3>
<p>Using this command to check the version of your kernel</p>

```bash
uname -r  ##check the version
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.1.6.tar.xz 
## Get the tar.xz file,my version is 5.1.6
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
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/2.png"> </p>


<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/3.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/4.png"> </p>

<p>We use this 'gpg --recv-keys' command but the error is no keyserver, the correct command should be </p>

```bash
gpg --keyserver <keyservername> --recv-keys "key-ID"
## Here for the <keyservername>, we use 'keyserver.ubuntu.com'

```

<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/5.png"> </p>

<p>But there still have a problem, firstly we install this kernel in Ubuntu 18.04 and 20.04, then we try the key of those version, it works. </p>
<p><font color = "red" >Sample output:</font> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/6.png"> </p>

<h>Now,we get the "linux-5.1.6.tar" file. Then untar this tarball.</h>

```bash
tar xvf linux-5.1.6.tar

```
<p>Here we get this dic "linux-5.1.6"</p>
<p>Before start building the kernel,one must configure Linux kernel features.Then copy existing config file from your /boot</p>

<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/7.png"> </p>

```bash
cd linux-5.1.6 ## Enter linux-5.1.6 dic 
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

<p>After installing these package</p>

```bash
make menuconfig ## Start the kernel configuraion 
```
<p>Sample output</p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/make_menuc.png"> </p>
<p> after making, this is an menu then you can see some details about configuration. Also you can exit it, then the terminal will show '*** Execute 'make' to start the build '</p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/11.png"> </p>



<p>Start compiling, just use 'make'; or to speed up time, use 'make -j $(nproc)'</p>
<p>It will take a lot of time</p>

```bash
## my cpu core is 4 becasue I set 4
make -j 4 ## Start to compile
```


<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/12.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/process1.png"> </p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/process2.png"> </p>
<p>Install the Linux kernel modules</p>

```bash
## Now using this command
sudo make modules_install
```
 <p>After installing kernel modules, you will see the version of your kernel in the last</p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/modules_install.png"> </p>

<p>Then I use 'uname -r' to see the version,luckily it is 4.15.0.😑 Because I have not compiled the kernel and the modules.</p>


```bash
sudo make install ## last part
```
<p><b>Sample output</b></p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/13.png"> </p>

```bash
ls -a /boot ## To see all files in /boot
```
</h3>

<p><b>Now there have 3 kernel_5.1.6 files:</b></p>
<p><b>1. initrd.img-5.1.6</b></p>
<p><b>2. System.map-5.1.6</b> </p>
<p><b>3. vmlinuz-5.1.6:</b></p>

<p></p>If you want to know more information,this web would give a hand:
<p><a href="https://developer.ibm.com/articles/l-initrd/">https://developer.ibm.com/articles/l-initrd/</a></p>
<p><a href="https://s905060.gitbooks.io/site-reliability-engineer-handbook/content/anatomy_of_the_initrd_and_vmlinuz.html">https://s905060.gitbooks.io/site-reliability-engineer-handbook/content/anatomy_of_the_initrd_and_vmlinuz.html</a></p>


<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/14.png"> </p>
<h3>
<p>Now,everything is ready and then upgrade grub.</p>

```bash
sudo update-initramfs -c -k 5.1.6
sudo update-grub

```

<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/15.png"> </p>


```bash
## After finishing, reboot ubuntu
reboot
## ...A few minutes later

uname -r
## you will see your version 😁
```

<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/16.png"> </p>
</h3>

# 2.Problems 

- <h3>Disk free space problem</h3>
<p>When install the Linux kernel modules( about 9.4G for kernel version 5.1.6), there will be error when the system disk free space is not big enough--the default value for create the virtual machine is 20G, it means that the real free space for such that new virtual machine is only less than 10G(system application occupy certain space).</p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/space_problem.png"> </p>
<h3>Solution:</h3>
<p>Using the command to install disk management software in ubuntu:</p>

```bash
sudo apt install gparted
```


<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/gparted.png"> </p>

<p><font size="20">After downloading the GParted Partition Editor, search and open it on system application, then expand the disk capacity to more than 20 GB.
</font></p>
<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/gparted2.png"> </p>

- <h3>Receive key failed</h3>
<p>After reading a lot of blog and find the manual of 'pgp', --keyserver is a must for this command</p>

```bash
man gpg ##check the manual of gpg
```

<p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/key_error.png"> </p>

- <h3>Compilation error in Ubuntu 20.04 </h3>
In the step of 'make', there are thousands of errors in compilation.For example:some function are not compatible, then it fails.
 <p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/error20.jpg"> </p>
 <p> <img src="https://github.com/niehmanyo/linux/blob/main/3.Ubuntu16.04_install_kernel_5.1.6/20error.jpg"> </p>
 <h3>Solution:</h3>
 <p>Change to Ubuntu 16.04,then do the compilation </p>


# 3.Further reading

 <h3>initrd.img</h3>
 The initial RAM disk (initrd) is an initial root file system that is mounted prior to when the real root file system is available. The initrd is bound to the kernel and loaded as part of the kernel boot procedure.
 <h3>System.map</h3>
  The system.map file records the running addresses of all symbols, which can be understood as function names and variables. The System.map file can help us understand kernel compilation. The system.map file is not a layer invariant and is regenerated each time the kernel is compiled.
 <h3>vmlinuz</h3>
 vmlinuxz(Virtual Memory LINUx gZip) is the name of the Linux kernel executable. vmlinuz is a compressed Linux kernel, and it is capable of loading the operating system into memory so that the computer becomes usable and application programs can be run

<p></p>If you want to know more information,this web would give a hand:
<p><a href="https://developer.ibm.com/articles/l-initrd/">https://developer.ibm.com/articles/l-initrd/</a></p>
<p><a href="https://s905060.gitbooks.io/site-reliability-engineer-handbook/content/anatomy_of_the_initrd_and_vmlinuz.html">https://s905060.gitbooks.io/site-reliability-engineer-handbook/content/anatomy_of_the_initrd_and_vmlinuz.html</a></p>

 <h3>what is 'make menuconfig'?</h3>
'menuconfig':Provide an interacting way to make kernel configuration based on a menu.
<h4>Some useful configurations/setup</h4>

 1.  General setup-> System V IPC (Inter Process Communication), it is a set of systems and function libraries that allow programs to exchange information synchronously with each other. Provides a communication mechanism for processes, which will enable processes in the system to exchange information and maintain synchronization.

2.  Loadable module support -> Enable loadable module support, this option allows the kernel to support modules. PS: modules is a piece of code; Some less commonly used drivers or features can be compiled into modules to reduce the size of the kernel.

3.  Loadable module support -> Automatic kernel module loading, which can automatically call the ‘modprobe’ command to load modules or the command need to be called manually.

4.  Processor type and features, Linux can support a variety of PC standards based on this option, generally the PCs we use follow the so-called IBM-compatible architecture (pc/at). This option lets users choose some other architecture.

5.  File System -> Ext2 extended attributes
                Ext2 POSIX Access Control Lists
                Ext2 Security Labels
                Ext3 extended attributes
                Ext3 POSIX Access Control Lists
                Ext3 Security Labels

