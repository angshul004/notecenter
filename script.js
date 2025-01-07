document.getElementById('toggleButton').addEventListener('click', function() {
    var modules = document.getElementById('modules');
    modules.classList.toggle('show');
  });
  
// View PDF
var buttons = document.querySelectorAll('.viewButton');
buttons.forEach(function(button) {
  button.addEventListener('click', function() {
    var url = this.getAttribute('data-url');
    openPDF(url);
  });
});

function openPDF(url) {
  var maxAttempts = 5; // Adjust the maximum number of attempts
  var attempt = 0;
  var newWindow = window.open(url, '_blank');

  function reloadWindow() {
    attempt++;
    if (attempt >= maxAttempts) {
      console.error('Failed to load the URL after ' + maxAttempts + ' attempts.');
      return;
    }

    setTimeout(function() {
      if (newWindow && newWindow.document) {
        var body = newWindow.document.body;
        if (body && (body.innerHTML === '' || body.innerHTML === '<html><head></head><body></body></html>' || body.textContent.trim() === '')) {
          newWindow.location.reload();
          reloadWindow();
        } else {
          console.log('URL loaded successfully!');
        }
      } else {
        newWindow.location.reload();
        reloadWindow();
      }
    }, 1500);
  }

  reloadWindow();
}

  
  
