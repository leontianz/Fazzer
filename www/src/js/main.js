var Web = {
   OnReady: function(){
      // Get the form element and bound the event handler to it.
      var form = document.getElementById( 'base-info-form' );
      form.addEventListener( 'submit', Form.OnSubmitHanle );
   }
}

var Ajax = {
   PostRequest: function( url, data, callBack ){
      Ajax.AsyncRequest( 'post', url, data, callBack );
   },

   AsyncRequest: function( methor, url, data, callBack ){
      Ajax.BaseRequest( methor, url, data, callBack, true );
   },

   BaseRequest: function( methor, url, data, callBack, isAsync ){
      var xhr = Ajax.CreateXHR();

      xhr.onreadystatechange = function(){
         if( xhr.readyState == 4 ){
            if( ( xhr.status >= 200 && xhr.status < 300 ) || ( xhr.status == 304 ) ){
               console.log( 'Get the valid data form the backend...' );
               callBack( xhr.responseText );
            }else{
               console.log( 'The ERROR occur. xhr.status: ' + xhr.status );
            }
         }
      }

      // Open the xhr.
      xhr.open( methor, url, isAsync );
      xhr.setRequestHeader( 'Content-Type', 'application/x-www-form-urlencoded' );

      if( methor == 'post' ){
         xhr.send( data );
      }else{
         xhr.send( null );
      }

   },

   CreateXHR: function(){
      // TODO: Cerate the XMLHttpRequest object adapt the different browser.
      return new XMLHttpRequest();
   }
}

var Form = {
   OnSubmitHanle: function( event ){
      // Forbidding the defult behavior firstly.
      event.preventDefault();

      // Serialize the form
      var formData = Form.Serialize( this );

      // Submit the data of form by Ajax.
      Ajax.PostRequest( 'server.fcgi', formData, Form.ResponseCallBack );
   },

   Serialize: function( form ){
      var content = [];
      var allElement = form.elements;

      for( var index = 0; index < allElement.length; index++ ){
         var element = allElement[index];

         if( element.type == 'submit' || element.type == 'reset' ){
            continue;
         }

         content.push( encodeURIComponent( element.name) + '=' + encodeURIComponent( element.value ) );
      }

      return content.join( '&' );
   },

   ResponseCallBack: function( responseText ){
      console.log( 'Yes, I got the respond data from the server side!!!' );
      console.log( responseText );
   }
}
