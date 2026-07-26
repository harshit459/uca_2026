fetch("https://gorest.in/public/v2/users")
.then(function(response) {
    return response.json();
})
.then(function(users) {

    if(users.length == 0){
        postMessage("No users found");
        return;
    }

    for(var i = 0; i < users.length; i++){

        if(users[i].status == "active"){
            postMessage(users[i].name + " - Active");
        }
        else{
            postMessage(users[i].name + " - Inactive");
        }

    }

})
.catch(function(error){
    console.log(error + " " + error.message);
    postMessage("Error: " + error.message);
});
