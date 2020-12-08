
#!/bin/bash


function new_user()
{
    usr=$1
    comment=$2

    id $usr >/dev/null 2>&1 && return
    echo create user $usr  $comment

    useradd -mU -s /bin/bash -p $(openssl passwd $usr) -c "$comment" $usr
    echo ""
}


if [ -n "$1" ]; then
    new_user $@
else
    new_user ian Ian.Xu
fi

