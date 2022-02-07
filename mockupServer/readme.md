# to disable sw type in chrome cmd:

```javascript
navigator.serviceWorker.getRegistrations()
.then(function (registrations) {
  for (let registration of registrations) {
    registration.unregister();
  }
});
```
