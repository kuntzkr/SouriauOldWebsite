<div class="b-form">
  <form>
    <fieldset>
      <legend>Edit address</legend>

      <div class="form-item form-type-textfield">
        <label for="name">First name</label>
        <input id="name" class="form-text" type="text" name="name" value="Jason Alexander"/>
      </div>

      <div class="form-item form-type-textfield">
        <label for="name2">Last name</label>
        <input id="name2" class="form-text" type="text" name="name2"  value="Warner"/>
      </div>

      <div class="form-item form-type-textfield">
        <label for="address1">Address</label>
        <input id="address1" class="form-text" type="text" name="address1" />
      </div>

      <div class="form-item form-type-textfield">
        <label for="address2">Address</label>
        <input id="address2" class="form-text" type="text" name="address2" />
      </div>

      <div class="form-row">
        <div class="form-item form-type-textfield a-left">
          <label for="zip-code">Zip Code</label>
          <input id="zip-code" class="form-text" type="text" value="1111" name="zip-code" />
        </div>

        <div class="form-item form-type-textfield a-right">
          <label for="city">City</label>
          <input id="city" class="form-text" type="text" name="city" />
        </div>
      </div>

      <div class="form-item form-type-select">
        <label for="country">Country</label>
        <select id="country" aria-multiselectable="false" class="default">
          <option>Select country</option>
          <option selected>France</option>
          <option>Ukraine</option>
          <option>Germany</option>
        </select>
      </div>

      <div class="form-item form-type-textfield">
        <label for="phone">Phone</label>
        <input id="phone" class="form-text" type="text" name="phone" />
      </div>

      <div class="form-item form-type-textfield">
        <label for="m-phone">Mobile phone</label>
        <input id="m-phone" class="form-text" type="text" name="m-phone" value="11111111" />
      </div>

      <div class="form-item form-type-textfield">
        <label for="adr-name">Name this address</label>
        <input id="adr-name" class="form-text" type="text" name="adr-name" />
      </div>
    </fieldset>
    <div class="form-block form-actions text-center">
      <div class="align-btn-center">
        <button class="btn orange-btn-hover a-right">UPDATE THIS ADDRESS</button>
        <a href="#" class="btn blue-btn close-btn">CANCEL</a>
      </div>
    </div>
  </form>
</div>