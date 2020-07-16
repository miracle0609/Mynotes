## `urllib` 模块

有如下四个模块

1、`urllib.requests`

2、`urllib.error`  

3、`urllib.parse`  解析和处理URL

4、`urllib.robot parse`

```python
#!/usr/bin/env python
# coding=utf-8
"""urllib的使用"""
import urllib.request

#向制定一个URL发送请求，获取回应
response = urllib.request.urlopen("http://www.fangsong.run")
#获取响应内容
content = response.read().decode('utf-8')
fo = open('./fangsong.html', 'w', encoding = 'utf-8')
print(content, file = fo)
fo.close()


#响应头信息
print(response.headers)
#响应码
print(response.status)
```

```python
Connection: close
Content-Length: 48327
Server: GitHub.com
Content-Type: text/html; charset=utf-8
Strict-Transport-Security: max-age=31556952
Last-Modified: Fri, 10 Jul 2020 01:36:45 GMT
ETag: "5f07c62d-bcc7"
Access-Control-Allow-Origin: *
Expires: Thu, 16 Jul 2020 11:33:23 GMT
Cache-Control: max-age=600
X-Proxy-Cache: MISS
X-GitHub-Request-Id: 4A5E:2A37:12F5B9:1755F1:5F1038AA
Accept-Ranges: bytes
Date: Thu, 16 Jul 2020 11:32:11 GMT
Via: 1.1 varnish
Age: 528
X-Served-By: cache-hkg17935-HKG
X-Cache: HIT
X-Cache-Hits: 1
X-Timer: S1594899132.629190,VS0,VE1
Vary: Accept-Encoding
X-Fastly-Request-ID: ea09594f3e3d38c033755ede864ce735303f9638


200
```

##　安装虚拟环境

https://www.cnblogs.com/chjxbt/p/10517952.html

**一、问题：为什么要搭建虚拟环境**

在开发过程中，当需要使用python的某些工具包/框架时需要联网安装。比如联网安装Flask框架flask-0.10.1版本

```
sudo pip install flask==0.10.1
```

使用如上命令，会将flask-0.10.1安装到/usr/local/lib/python3.5/dist-packages路径下

如果在一台电脑上，想开发多个不同的项目， 需要用到同一个包的不同版本， 如果使用上面的命令， 在同一个目录下安装或者更新， 新版本会覆盖以前的版本， 其它的项目就无法运行了。

**二、解决方案：虚拟环境**

虚拟环境可以搭建独立的Python运行环境，使得单个项目的运行环境与其他项目互不影响。

**三、如何搭建虚拟环境（Linux系统）**

步骤：

1、安装虚拟环境

```
sudo apt-get install virtualenv
sudo apt-get install virtualenvwrapper
```

 安装完虚拟环境后，如果提示找不到`mkvirtualenv`命令，须配置环境变量：

```python
# 1、在~（家目录）下创建目录用来存放虚拟环境
mkdir ~/.virtualenvs

# 2、打开~/.bashrc文件，并添加如下：
export WORKON_HOME=$HOME/.myvirtualenvs
source /usr/share/virtualenvwrapper/virtualenvwrapper.sh

# 3、运行
source ~/.bashrc
```

**四、如何使用虚拟环境**

![undefined](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt3lfllh5j30k00bb3zt.jpg)

*创建环境*

```python
cd ~/.myvirtualenvs
mkvirtualenv -p /usr/bin/python3 Python3
```

上面命令第二个`python3`可以自定义

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt39wmrl0j30q90a8wno.jpg)

*进入与退出环境*

```bash
fangsong@fangsong-FX503VD:~/.myvirtualenvs$ workon Python3
(Python3) fangsong@fangsong-FX503VD:~/.myvirtualenvs$ deactivate
```

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt3iojlt9j30i501x0tl.jpg)

*安装requests*

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt3zxs982j30qf0fads6.jpg)