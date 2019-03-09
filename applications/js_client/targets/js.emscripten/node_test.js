var lcc;
var mdns = require('mdns');
var port = 12018
var browser;

require('./js_client.js')().then(function(Module) {
    lcc = Module
    lcc.startTcpHub(port)
    console.log('starting stack')
    try {
        lcc.startStack();
    } catch (e) {
        if (e === 'SimulateInfiniteLoop') {
            console.log('stack started.');
            lcc.afterStartStack();
        } else {
            console.log('unknown exception');
            throw e;
        }
    }
    browser = new lcc.NodeBrowser(function(node_id) {
        console.log('new node ' + node_id)
    })
});

var ad = mdns.createAdvertisement(mdns.tcp('openlcb-can'), port, {name: 'openmrn-node-test'} );
ad.start();
