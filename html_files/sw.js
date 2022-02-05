self.addEventListener('install', (e) => {
    e.waitUntil(
      caches.open('fox-store').then((cache) => cache.addAll([
        'html_IRController.html',
        'IRcontroller.js',
        'style.css',
      ])),
    );
  });
  
  self.addEventListener('fetch', (e) => {
    console.log(e.request.url);
    e.respondWith(
      caches.match(e.request).then((response) => response || fetch(e.request)),
    );
  });