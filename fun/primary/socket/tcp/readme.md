# 标准socket--tcp/ip通讯
- SOCK_STREAM：即TCP，工作在传输层，进程之间通信（IP＋端口），需要先建立连接，保证数据的完整性和有序性，有分包机制，有流量控制机制
- long_client.c
  - 超时连接的IP不能为127.0.0.1，否则立即返回
- long_server.c
  - 非阻塞socket accept返回错误值11