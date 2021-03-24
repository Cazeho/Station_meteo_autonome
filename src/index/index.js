Firebase.enableLogging(true);
var f = new Firebase('https://stma-a0c23-default-rtdb.firebaseio.com/temperature');

f.transaction(function(curr) {
}, function() {
    // Once the transaction has completed, update the UI (and watch for updates).
    f.on('value', function(s) {
      document.getElementById('contents').innerHTML = s.val();
    });
  });