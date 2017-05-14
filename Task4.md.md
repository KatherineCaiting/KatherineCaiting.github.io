## **Task4 summary**

------
## **前言**
刚开始时还是有点手足无措，于是便只是按照学长给的视频一点一点搞，结果我差点忘了要图文并茂。经过安虚拟机--安Windows sever 2003--搭建环境--将网页导入--系统设置--系统参数设置--制作网页模板--发布新闻等几个流程，我算是勉强搞出点了。*（Ps:我有点不太会写总结，希望组长能够见谅并给出改正建议）*

------
## **主要过程**： ##

> * 环境搭建
> * 搭建风讯cms基本新闻站点
> * 系统设置
> * 模板的制作
> * 发布新闻

------
## **参考路径**： ##

##### [Vm虚拟机的安装](http://www.cr173.com/html/22785_1.html)
##### [Vm虚拟机中安装Windows sever 2003](http://wenda.tianya.cn/question/612f904ea09eab9e)
##### [Windows sever2003中安装IIS](http://help.foosun.net/html/install/2006-6/5/06651202551544561.html)
##### [搭建ASP网站](http://blog.sina.com.cn/s/blog_624a83600100sy70.html)
##### [风讯网站内容管理系统--风讯官方站](http://help.foosun.net/)
##### [爱心便当](http://pan.baidu.com/s/1miSFZy4)(密码：87sq）
##### [通关秘籍](http://pan.baidu.com/s/1c2aN6ZA)(密码：ru6h)

----------
##详细过程

 一. 环境搭建
 1、安装虚拟机后，打开，点击创建虚拟机<br/>
 ![1][1]<br/>
 2、点击典型<br/>
 ![2][2]<br/>
 
 3、点击浏览，选择映像文件<br/>
 ![3][3]<br/>
 
 4、在网上找windows的密匙，输入<br/>
 ![4][4]<br/>
 
 5、浏览选择如图<br/>
 ![5][5]<br/>
 6、设置磁盘<br/>
 ![6][6]<br/>
 7、点击完成<br/>
 ![7][7]<br/>
 

 二.安iss6.0服务器
 1、打开windows sever 2003<br/>
 ![8][8]<br/>
 2、在菜单栏中找到”虚拟机“--设置--选择CD/DVD(IDE)--勾选已连接、启动时连接--使用映像文件<br/><br/>
 ![9][9]<br/>
 3、选择安装windows组件<br/>
 ![10][10]<br/>
 4、选择网络服务、应用程序服务器<br/>
 ![11][11]<br/>
 5、勾选如图<br/><br/>
 ![12][12]<br/>
 6、在应用程序服务器中点击详细信息，勾选internet信息服务管理器、公用文件、万维网服务<br/>
![13][13]<br/>
7、完成windows组件向导<br/>
![14][14]<br/>
8、打开“我的电脑”，选择“管理”，打开“本地用户和组”，选择“用户”<br/>
![15][15]<br/>
9、右键点击新建一个新用户<br/>
![16][16]<br/>
10、选定新建用户，右键打开“属性”，常规中勾选如图：<br/>
![17][17]<br/>
在“隶属于”中选择“添加”，再选择“高级”<br/>
![18][18]<br/>
选定“立即查找”、找到“guest”,应用<br/>
![19][19]<br/>

 三、配置风讯后台
 

 1. 、将风讯5.0文件导入到c盘中*（若不能复制，请重新安装VMware tools。若还是不行，我的方法是通过U盘连接，复制到C盘。）*
 2、打开配置好了的iss,选择“本地计算机”下的“网站”，新建网站，起个名字<br/>
 ![20][20]<br/>
 3、右键点击“新建的网站”，选择“属性”，网站下进行设置如图<br/>
![21][21]<br/>
“主目录”下设置路径如图<br/>
![22][22]<br/>
在“位置”中选择“选项”，勾选“启用父路径”如图<br/>
![23][23]<br/>
“文档”下设置，删掉原有的选项，再添加，如图<br/>
![24][24]<br/>
4、在“目录安全性”下选择“编辑”，在“用户”上选择刚新建的用户，输入密码，如图<br/>
![25][25]<br/>
5、再在“新建的网站”下，选择“权限”--“添加”--“高级”--“立即查找”--选择自定义的名称如图<br/>
 ![26][26]<br/>
 6、在新用户权限上勾选除“完全控制”的选项<br/>
 ![27][27]<br/>
 7、在“web服务器扩展”中将asp设置为允许<br/>
 ![28][28]<br/>
 8、在新建的网站下找到“yzadmin”,然后在其中找到“Login.asp”,右键点击“浏览”<br/>
![29][29]<br/>
 9、进入风讯5.0后台，输入用户名（admin）、密码(123456)<br/>
 ![30][30]<br/>
 10、进入后台，在“系统参数”下的“参数配置”中修改“本站域名”（id地址）<br/>
 ![31][31]<br/>
 

 四、上传网页、发布新闻
 
 1、将所要上传的网页模板导入到C盘风讯5.0的templets中,并且将templets中原有的文件删除<br/>
 ![32][32]<br/>
 2、在管理后台模版下选定“模板”<br/>
 ![33][33]<br/>
 3、点击(index.html、list.html和content.html)“文本编辑”，这时看到的文本是乱码的，所以需要外部将其中的“UTF-8”改为“gb2312”，再复制到这里,并将有关路径前加“/Templets/”<br/>
 ![34][34]<br/>
4、改完后，点击“更新缓存”，再打开“预览”<br/>
![35][35]<br/>

5、确定无误后，打开“发布管理”--“新闻”--分别在”按照栏目发布“和“选择栏目”里填写好栏目名称<br/>
![36][36]<br/>
在后台右侧的“栏目管理”中打开“添加根栏目”，填写好相关内容如图：<br/>
![37][37]<br/>
![38][38]<br/>
在“系统参数设置”中继续填写好相关内容，如图：<br/>
![39][39]<br/>![40][40]<br/>

6、确定无误后，点击发布“所有选项”“发布栏目”<br/>
![42][41]<br/>
点击发布“发布新闻”<br/>
![42][42]<br/>
点击发布“发布新闻主页”<br/>
![41][43]<br/>
点击“站点主页”、发布“开始发布站点主页”<br/>
![44][44]<br/>
7、选定上侧的“标签库”，打开“创建标签”，创建如图的标签<br/>
![45][45]<br/>
填好相关内容，打开“新闻列表”<br/>![46][46]<br/>
填好如图内容<br/>![47][47]<br/>

8、新建“内容页通用标签”时，如图<br/>
![48][48]<br/>
接着打开“新闻常规”<br/>
![49][49]<br/>
9、列表页时，如图<br/>
![50][50]<br/>
10、打开上侧的“样式管理”<br/>
![51][51]<br/>
修改下“新闻显示”中的编码，修改成如图<br/>
![52][52]<br/>
11、将{FS400_400学校要闻}插入到index.html文件中，将{FS400_400列表页通用标签}插入到list.html中<br/>

![53][53]<br/>
![54][54]<br/>
12、编辑一篇新闻，打开右侧的“新闻管理”，点击“add”,添加如图<br/>
![55][55]<br/>
![56][56]<br/>
编辑新闻内容<br/>
![57][57]<br/>
13、再如上发布一次新闻，浏览<br/>
![58][58]<br/>
14、同上，新建一个“位置导航”，将标签插到三个文件中<br/>**粗体文本**
![59][59]![60][60]![61][61]
15、确定无误后，浏览并修改，如图：<br/>
![62][62]<br/>
![63][63]![64][64]

 

----------
## **小结** ##
>总体来说进行得不是很顺利，不过我相信会越来越好的，一回生二回熟，在此也非常感谢学长给的大量帮助和组中小伙伴的帮忙。


------
> 谢谢观看

作者 [@katherineting]     
2017 年 04月 23日    


  [1]: http://a.hiphotos.baidu.com/image/pic/item/1ad5ad6eddc451da299f1ff6bcfd5266d0163245.jpg
  [2]: http://b.hiphotos.baidu.com/image/pic/item/359b033b5bb5c9ea341f1afedf39b6003af3b33a.jpg
  [3]: http://d.hiphotos.baidu.com/image/pic/item/6c224f4a20a446230aeabe7f9222720e0cf3d78e.jpg
  [4]: http://d.hiphotos.baidu.com/image/pic/item/4e4a20a4462309f79389b70f780e0cf3d6cad6cc.jpg
  [5]: http://b.hiphotos.baidu.com/image/pic/item/8718367adab44aedff60bff9b91c8701a18bfb85.jpg
  [6]: http://h.hiphotos.baidu.com/image/pic/item/5366d0160924ab180824e22a3ffae6cd7b890bf8.jpg
  [7]: http://e.hiphotos.baidu.com/image/pic/item/cdbf6c81800a19d8d0f8871839fa828ba61e4637.jpg
  [8]: http://f.hiphotos.baidu.com/image/pic/item/3b87e950352ac65c0d2e6a6ef1f2b21193138a87.jpg
  [9]: http://f.hiphotos.baidu.com/image/pic/item/f636afc379310a5506f4d0e9bd4543a9832610de.jpg
  [10]: http://a.hiphotos.baidu.com/image/pic/item/3801213fb80e7bec6c180bfc252eb9389a506be8.jpg
  [11]: http://h.hiphotos.baidu.com/image/pic/item/d4628535e5dde711af8c36ebadefce1b9d166154.jpg
  [12]: http://g.hiphotos.baidu.com/image/pic/item/7dd98d1001e939010f18fc2371ec54e736d19690.jpg
  [13]: http://a.hiphotos.baidu.com/image/pic/item/bba1cd11728b4710c1c38dd1c9cec3fdfc03233a.jpg
  [14]: http://c.hiphotos.baidu.com/image/pic/item/622762d0f703918f7ae542d75b3d269759eec4f3.jpg
  [15]: http://a.hiphotos.baidu.com/image/pic/item/1ad5ad6eddc451da01b477f5bcfd5266d0163269.jpg
  [16]: http://h.hiphotos.baidu.com/image/pic/item/86d6277f9e2f07089744501ee324b899a901f26f.jpg
  [17]: http://c.hiphotos.baidu.com/image/pic/item/34fae6cd7b899e5185b05e0a48a7d933c8950df5.jpg
  [18]: http://e.hiphotos.baidu.com/image/pic/item/a1ec08fa513d26978dc869435ffbb2fb4316d891.jpg
  [19]: http://b.hiphotos.baidu.com/image/pic/item/a6efce1b9d16fdfa9e9fa7f0be8f8c5494ee7b38.jpg
  [20]: http://c.hiphotos.baidu.com/image/pic/item/34fae6cd7b899e518da3560a48a7d933c8950dfa.jpg
  [21]: http://h.hiphotos.baidu.com/image/pic/item/0d338744ebf81a4cb65c82d7dd2a6059252da646.jpg
  [22]: http://d.hiphotos.baidu.com/image/pic/item/0824ab18972bd4074e7cbae371899e510fb30970.jpg
  [23]: http://e.hiphotos.baidu.com/image/pic/item/2e2eb9389b504fc2c137e21befdde71190ef6d47.jpg
  [24]: http://g.hiphotos.baidu.com/image/pic/item/2934349b033b5bb527ed4be03cd3d539b600bcf2.jpg
  [25]: http://b.hiphotos.baidu.com/image/pic/item/38dbb6fd5266d0167810c9369d2bd40735fa35a6.jpg
  [26]: http://c.hiphotos.baidu.com/image/pic/item/03087bf40ad162d9485136021bdfa9ec8a13cd75.jpg
  [27]: http://d.hiphotos.baidu.com/image/pic/item/8718367adab44aedb5a2e1fab91c8701a08bfbc4.jpg
  [28]: http://e.hiphotos.baidu.com/image/pic/item/cdbf6c81800a19d858eb0f1b39fa828ba71e46c0.jpg
  [29]: http://b.hiphotos.baidu.com/image/pic/item/ae51f3deb48f8c545de4303130292df5e0fe7ffd.jpg
  [30]: http://h.hiphotos.baidu.com/image/pic/item/d000baa1cd11728bb0547c3cc2fcc3cec3fd2cb7.jpg
  [31]: http://c.hiphotos.baidu.com/image/pic/item/43a7d933c895d143b7e6163d79f082025aaf071f.jpg
  [32]: http://a.hiphotos.baidu.com/image/pic/item/bba1cd11728b471049c205d2c9cec3fdfc03233b.jpg
  [33]: http://e.hiphotos.baidu.com/image/pic/item/0df431adcbef7609d784628124dda3cc7cd99e25.jpg
  [34]: http://c.hiphotos.baidu.com/image/pic/item/faf2b2119313b07e402fb71606d7912397dd8c1a.jpg
  [35]: http://d.hiphotos.baidu.com/image/pic/item/71cf3bc79f3df8dc325c6f8fc711728b4710284f.jpg
  [36]: http://a.hiphotos.baidu.com/image/pic/item/11385343fbf2b211135f6a50c08065380cd78ebf.jpg
  [37]: http://e.hiphotos.baidu.com/image/pic/item/d058ccbf6c81800ae552190abb3533fa828b477b.jpg
  [38]: http://b.hiphotos.baidu.com/image/pic/item/42a98226cffc1e17dbc41f354090f603738de9bf.jpg
  [39]: http://g.hiphotos.baidu.com/image/pic/item/8435e5dde71190efe8a445c1c41b9d16fdfa6055.jpg
  [40]: http://c.hiphotos.baidu.com/image/pic/item/eaf81a4c510fd9f9b5aa82772f2dd42a2834a46b.jpg
  [41]: http://h.hiphotos.baidu.com/image/pic/item/f9dcd100baa1cd11a562a33eb312c8fcc2ce2ddc.jpg
  [42]: http://e.hiphotos.baidu.com/image/pic/item/aec379310a55b319e77f526b49a98226cffc172d.jpg
  [43]: http://a.hiphotos.baidu.com/image/pic/item/7e3e6709c93d70cfeb397a13f2dcd100bba12be9.jpg
  [44]: http://g.hiphotos.baidu.com/image/pic/item/f31fbe096b63f6243d37eb1d8d44ebf81a4ca342.jpg
  [45]: http://h.hiphotos.baidu.com/image/pic/item/b812c8fcc3cec3fd2b16786bdc88d43f87942780.jpg
  [46]: http://h.hiphotos.baidu.com/image/pic/item/21a4462309f79052df739e2006f3d7ca7bcbd544.jpg
  [47]: http://d.hiphotos.baidu.com/image/pic/item/738b4710b912c8fc10192fd3f6039245d78821c2.jpg
  [48]: http://e.hiphotos.baidu.com/image/pic/item/d52a2834349b033b07f226c41fce36d3d539bdb2.jpg
  [49]: http://b.hiphotos.baidu.com/image/pic/item/55e736d12f2eb9381276bfecdf628535e5dd6f91.jpg
  [50]: http://b.hiphotos.baidu.com/image/pic/item/f2deb48f8c5494ee6949cb0727f5e0fe99257e41.jpg
  [51]: http://f.hiphotos.baidu.com/image/pic/item/0824ab18972bd407d03e14e371899e510fb30937.jpg
  [52]: http://d.hiphotos.baidu.com/image/pic/item/72f082025aafa40fb8e90fc3a164034f78f01985.jpg
  [53]: http://d.hiphotos.baidu.com/image/pic/item/0823dd54564e925872dc44f09682d158cdbf4ec0.jpg
  [54]: http://d.hiphotos.baidu.com/image/pic/item/91ef76c6a7efce1b164a05d4a551f3deb48f654f.jpg
  [55]: http://a.hiphotos.baidu.com/image/pic/item/29381f30e924b899b16ab62664061d950a7bf65e.jpg
  [56]: http://d.hiphotos.baidu.com/image/pic/item/63d9f2d3572c11df8a73713d692762d0f703c20a.jpg
  [57]: http://g.hiphotos.baidu.com/image/pic/item/7dd98d1001e93901577b442071ec54e736d196b7.jpg
  [58]: http://a.hiphotos.baidu.com/image/pic/item/024f78f0f736afc331ccac61b919ebc4b64512f5.jpg
  [59]: http://a.hiphotos.baidu.com/image/pic/item/4610b912c8fcc3ce0308fc2c9845d688d53f20e0.jpg
  [60]: http://d.hiphotos.baidu.com/image/pic/item/574e9258d109b3de0752d077c6bf6c81800a4c3b.jpg
  [61]: http://g.hiphotos.baidu.com/image/pic/item/79f0f736afc37931e4a2b236e1c4b74542a911e2.jpg
  [62]: http://c.hiphotos.baidu.com/image/pic/item/6a600c338744ebf88085f63bd3f9d72a6059a73a.jpg
  [63]: http://a.hiphotos.baidu.com/image/pic/item/f9dcd100baa1cd11ca4a443fb312c8fcc3ce2d34.jpg
  [64]: http://g.hiphotos.baidu.com/image/pic/item/cdbf6c81800a19d82222b51a39fa828ba61e468f.jpg