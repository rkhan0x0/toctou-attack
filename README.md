# Race condition (TOCTOU) vulnerability lab

Shows how Race Condition with Privileged Applications work

```bash
useradd attacker
```

Run the following steps as root user:

```bash
cc toctou.c -o toctou
chmod u+s toctou

cd /home/attacker
echo "only privileged user can edit this file" > ./passwd
```

Run the following steps as attacker

```bash
# copy your exploit.sh here
chmod +x exploit.sh

# compile the symlink.c

cc symlink.c -o symlink

# Run the exploit.sh

```

## References
- [Race condition (TOCTOU) vulnerability lab](https://resources.infosecinstitute.com/topic/race-condition-toctou-vulnerability-lab/)
